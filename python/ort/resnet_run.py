import sys
import onnx
import numpy as np
import onnxruntime as rt
import shutil, os
# from PIL import Image
import cv2
 

img_crop = {'x': 0, 'y': 210, 'w': 1280, 'h': 320}
model_img_size = {'w': 1280, 'h': 320}

def main(image, img_result_dir):

    # 加载onnx模型
    sess = rt.InferenceSession(sys.argv[1])

    # 打印输入输出节点信息
    input_name = sess.get_inputs()[0].name
    input_shape = sess.get_inputs()[0].shape
    output_name = []
    for node in sess.get_outputs():
        output_name.append(node.name)
    print("-- input_name: {}".format(input_name))
    print("-- input_shape: {}".format(input_shape))
    print("-- output_name: {}".format(output_name))

    # 读取测试txt文件
    image_arr = np.loadtxt(image).reshape([1, 3, 224, 224]).astype(np.float32)

    ## 推理
    scale_0 = sess.run(output_name, 
                {input_name:image_arr.astype(np.float32)})

    ## 保存推理结果
    scale_0 = np.array(scale_0)
    with open(img_result_dir + "/" + output_name[0] + '.txt', 'w') as f4:
        np.savetxt(f4, scale_0.reshape(-1), delimiter='\t', newline='\n')
    f4.close()
    print("-- save output tensor {} succeed".format(output_name[0]))

if __name__ == '__main__':
    
    if len(sys.argv) < 4:
        print(sys.argv)
        print("-- Invalid parameter, argv1:onnx model, argv2:input data, argv3:output path")
        exit(1)

    image_dir = sys.argv[2]
    result_dir = sys.argv[3]
    main(image_dir, result_dir)