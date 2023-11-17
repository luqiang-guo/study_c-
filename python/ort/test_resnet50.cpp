#include <ncnn/nova_net.h>
#include <ncnn/nova_mat.h>
#include <opencv2/opencv.hpp>
#include <novacl/novacl.hpp>

#include <time.h>
#include <sys/time.h>

constexpr float mean_vals[3] = {0.485*255,0.456*255,0.406*255};
constexpr float std_vals[3] = {0.229*255,0.224*255,0.225*255};
constexpr int resize_h = 224;
constexpr int resize_w = 224;
constexpr int outputnum = 1000;

// 从txt中加载数据,作为模型输入,省掉归一化的操作
int readStream(std::string fileName, float *buf) {  
    std::ifstream in;
    in.open(fileName, std::ios::in);
    if (!in.is_open()) {
        std::cout << "Open File Failed: " << fileName << std::endl;
        return -1;
    } else {
        std::cout<< "Open File Success: " << fileName << std::endl;
    }

    int i = 0;
    while (in.peek() != EOF) {
        in >> buf[i];
        i++;
    }
    in.close();
    return i;
}

void preProcess(cv::Mat& src,ncnn::NovaMat& input) {
    cv::Mat resize_src;
    cv::resize(src,resize_src,cv::Size(resize_w,resize_h));
    cv::cvtColor(resize_src, resize_src,
                    cv::COLOR_BGR2RGB);
    const uint8_t *in_ptr = (uint8_t *)resize_src.data;
    float *out_ptr = (float *)input.data;
    nova::normalizePacked(in_ptr, out_ptr, resize_h * resize_w * 3,
                    mean_vals, std_vals, 3);
}

// 将输入数据加载到NovaMat
void preProcess(std::string fileName,ncnn::NovaMat& input) {
    float *out_ptr = (float *)input.data;
    readStream(fileName, out_ptr);
}

void postProcess(cv::Mat& src,ncnn::NovaMat& output) {
  int max_id = 0;
  float max_score = 0.0;
  float* out_ptr = (float *)output;
  auto size = output.w *output.h * output.c;

// 保存输出结果为TXT
#if 1
  std::ofstream outFile;
  outFile.open("nova_float.txt");
  for (uint64_t i = 0; i < size; i++) {
      outFile << out_ptr[i];
      outFile << "\n";
  }
  outFile.close();
#endif

  for (auto i = 0; i < size; i++) {
    if (out_ptr[i] > max_score) {
      max_score = out_ptr[i];
      max_id = i;
    }
  }

  cv::putText(src, std::to_string(max_id), cv::Point2i(40, 40), cv::FONT_HERSHEY_PLAIN, 3,
              cv::Scalar(0, 0, 255));
}

int main(int argc, char** argv) {
    ncnn::NovaNet novanet;
    novanet.load_param("./resnet50_nomean.param");
    novanet.load_model("./resnet50_nomean.bin");
    novanet.opt.npu_id = 0; 
    novanet.opt.dump_io = 1;

    ncnn::NovaMat input(resize_w,resize_h,3,sizeof(float));//w,h,c
    ncnn::NovaMat output(outputnum);

#if 0
    cv::Mat src = cv::imread("./cat.jpg");
    preProcess(src,input);
#else //加载txt文件
    cv::Mat src = cv::imread("./cat.jpg");
    preProcess("input_cpu_hwc.txt",input);
#endif

#if 1 //运行单帧
    timeval t1, t2, t3, t4;
    double diffTime1, diffTime2, diffTime3;
    gettimeofday(&t1, NULL);
    ncnn::NovaExtractor nova_ex = novanet.create_extractor();
    
    gettimeofday(&t2, NULL);
    nova_ex.input("Input_1_tensor", input);
    
    gettimeofday(&t3, NULL);
    nova_ex.extract("DequantizeLinear_1", output);
    gettimeofday(&t4, NULL);
    
    diffTime1 = (double)(1000000 * (t2.tv_sec - t1.tv_sec) + t2.tv_usec - t1.tv_usec) / 1000.0;
    diffTime2 = (double)(1000000 * (t3.tv_sec - t2.tv_sec) + t3.tv_usec - t2.tv_usec) / 1000.0;
    diffTime3 = (double)(1000000 * (t4.tv_sec - t3.tv_sec) + t4.tv_usec - t3.tv_usec) / 1000.0;
    printf("create_extractor cost %f ms, input cost %f ms, extract cost %f ms.\n", diffTime1, diffTime2, diffTime3);
#else //连续运行
    timeval t1, t2;
    double diffTime1;
    ncnn::NovaExtractor nova_ex = novanet.create_extractor();
    for (int idx = 0; idx < std::atoi(argv[1]); ++idx) {
      int ret = -1;
      ret = nova_ex.input("Input_1_tensor", input);
      if (ret != 0) {
        printf("input error with %d\n", ret);
      } else {
        printf("input success.\n");
      }
      gettimeofday(&t1, NULL);
      ret = nova_ex.extract("DequantizeLinear_1", output);
      gettimeofday(&t2, NULL);
      if (ret != 0) {
        printf("extract error with %d\n", ret);
      } else {
        printf("extract success.\n");
      }
      diffTime1 = (double)(1000000 * (t2.tv_sec - t1.tv_sec) + t2.tv_usec - t1.tv_usec) / 1000.0;
      printf("extract cost %f ms.\n", diffTime1);
    }
#endif


    postProcess(src,output);
    cv::imwrite("result.jpg",src);

    return 0;
}
