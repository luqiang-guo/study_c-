#include <iostream> 
#include <vector>
#include <cmath>

// for(auto h = 0; h < dst_h; h++){
//   for(auto w = 0; w < dst_w; w++) {
//     for(auto c = 0; c < channel; c++) {
//       uint8_t bnf = naive_output_buf[h*dst_w*channel + w*channel +c];
//       uint8_t bof = opencv_output_buf[h*dst_w*channel + w*channel +c];

//       if(bnf != bof)
//         printf("hwc = (%d, %d, %d). %d, %d\n", h, w, c,  bnf, bof);

//     }
//   }
// }


// src = (336, 610). dst = (535, 201)
// 13655, 93, 96
// 13,375 25h 280w


// int32_t channel = 1;
// int32_t src_w = 336;
// int32_t src_h = 610;
// int32_t dst_w = 535;
// int32_t dst_h = 201;
// printf("src = (%d, %d). dst = (%d, %d)\n", src_w, src_h,dst_w, dst_h);


//   for(auto i = 0u; i < src_num; i++) {
//     src_buf[i] = (64 + i) %256;
//   }

// printf("hw = (%d, %d), %d, %.12f, %.12f, %.12f, %.12f\n", dh, dw, 
//     h_dst_ptr[dw * src_c + dc], rows_0_ptr[dw * src_c + dc], rows_1_ptr[dw * src_c + dc], b0, b1);


        // printf("%d, %d, %d\n", i, value[i], cmp_value[i]);
    // printf("%d, %d, (%f, %f)\n", dx, xofs[dx], alpha[dx * 2], alpha[dx * 2 + 1]);
void linearCoeffs(double scale, int x, float * fx, int32_t * index) 
{
    float tmp_fx = static_cast<float>((x + 0.5) * scale - 0.5);
    int32_t src_x_index = floor(tmp_fx);
    tmp_fx -= src_x_index;

    *index = src_x_index;
    *fx = tmp_fx;
    return;
}

int main (void) 
{
    int32_t channel = 1;
    int32_t src_w = 336;
    int32_t src_h = 610;
    int32_t dst_w = 535;
    int32_t dst_h = 201;

    printf("(%d, %d), (%d, %d), %d\n", src_w, src_h, dst_w, dst_h, channel);

    size_t src_num = src_w * src_h * channel;
    size_t dst_num = dst_w * dst_h * channel;

    std::vector<uint8_t> src_buf(src_num, 0);
    for(auto i = 0u; i < src_num; i++) {
        src_buf[i] = (64 + i) %256;
    }

    double scale_w = static_cast<double>(src_w) / static_cast<double>(dst_w);
    double scale_h = static_cast<double>(src_h) / static_cast<double>(dst_h);

    int w = 280;
    int h = 25;
    float fw;
    float fh;
    int32_t index_w;
    int32_t index_h;

    linearCoeffs(scale_w, w, &fw, &index_w);
    linearCoeffs(scale_h, h, &fh, &index_h);


    printf("w,h = (%d, %d), scale = (%f, %f)\n", index_w, index_h, fw, fh);

    float w1 = src_buf[index_w + src_w * index_h] * (1 - fw) + src_buf[index_w + 1 + src_w * index_h] * fw;
    float w2 = src_buf[index_w + src_w * (index_h + 1)] * (1 - fw) + src_buf[index_w + 1 + src_w * (index_h+1)] * fw;
    
    float out = w1 * (1 - fh) + w2 * fh;
    printf("w1 = %f, w2 = %f, out= %f \n", w1, w2, out);
    return 0;
}

// constexpr int INTER_RESIZE_COEF_BITS = 11;
// constexpr int INTER_RESIZE_COEF_SCALE = 1 << INTER_RESIZE_COEF_BITS;

// void wLinearCoeffsQFormat(uint32_t src_w, uint32_t dst_w, int32_t* w_ofs,
//                          int16_t* alpha, bool align_corner) {
//   double scale = static_cast<double>(src_w) / static_cast<double>(dst_w);
//   if (align_corner) {
//     scale = static_cast<double>(src_w - 1) / static_cast<double>(dst_w - 1);
//   }
  
//   for (uint32_t dw = 0; dw < dst_w; dw++) {

//     float fw = 0.0f;
//     int32_t sw = 0;
//     if (!align_corner) {
//       fw = static_cast<float>((dw + 0.5) * scale - 0.5);
//       sw = static_cast<int32_t>(floor(fw));
//       fw -= sw;
//     }else {
//       // TODO :
//       fw = static_cast<float>(dw * scale);
//     }

//     if (sw < 0) {
//       sw = 0;
//       fw = 0.f;
//     }
//     if (sw >= static_cast<int32_t>(src_w - 1)) {
//       sw = src_w - 1;
//       fw = 0.f;
//     }

//     w_ofs[dw] = sw;

//     alpha[dw * 2] = static_cast<int16_t>(__builtin_lrintf((1.f - fw) * INTER_RESIZE_COEF_SCALE));
//     alpha[dw * 2 + 1] = static_cast<int16_t>(__builtin_lrintf(fw * INTER_RESIZE_COEF_SCALE));

//     printf("w : %d. (%d, %d), (%f, %f)\n", w_ofs[dw], alpha[dw * 2], alpha[dw * 2 + 1], 1.f - fw, fw);
//   }
// }


        // h_dst_ptr[dw * src_c + dc] = static_cast<uint8_t>(( ( ( b0 * (rows0p[dw * src_c + dc] >> 4)  +
        //                          b1 * (rows1p[dw * src_c + dc] >> 4)) >> 16) + 2) >> 2);