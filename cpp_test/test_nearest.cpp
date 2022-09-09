#include <cstdint>
#include <iostream> 
#include <vector>

// 0
//   int32_t channel = 1;
//   int32_t src_w = 124;
//   int32_t src_h = 286;
//   int32_t dst_w = 215;
//   int32_t dst_h = 403;

//   printf("(%d, %d), (%d, %d), %d\n", src_w, src_h, dst_w, dst_h, channel);

// 1
// src = (175, 136). dst = (500, 175)
int main (void) 
{
    int32_t channel = 1;
    int32_t src_w = 175;
    int32_t src_h = 136;
    int32_t dst_w = 500;
    int32_t dst_h = 175;

    printf("(%d, %d), (%d, %d), %d\n", src_w, src_h, dst_w, dst_h, channel);

    size_t src_num = src_w * src_h * channel;
    size_t dst_num = dst_w * dst_h * channel;

    std::vector<uint8_t> src_buf(src_num, 0);
    for(auto i = 0u; i < src_num; i++) {
        src_buf[i] = (64 + i) %256;
    }

    double scale_w = static_cast<double>(src_w) / static_cast<double>(dst_w);
    double scale_h = static_cast<double>(src_h) / static_cast<double>(dst_h);

    int w = 180;
    int h = 0;
    int h_inedx = scale_w * w;

    printf("src index = %d \n", h_inedx);

    w = 62;
    h = 0;
    uint8_t value = src_buf[h * src_w + w];
    printf("value = %d \n", value);
    // h = 21;
    // value = src_buf[h * src_w + w];
    // printf("value = %d \n", value);
}