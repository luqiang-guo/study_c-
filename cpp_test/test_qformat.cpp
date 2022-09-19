#include <iostream>

// int64_t q15Floor(int64_t x) {
//   if(x >= 0) {
//     return x & (~0xffffffff);
//   } else {
//     return (x - ( ((int64_t)1) << 32))& (~0xffffffff);
//   }
// }


int32_t q15Floor(int32_t x) {
  if(x >= 0) {
    return x & (~((1 << 15) - 1));
  } else {
    return (x - (1 << 15)) & (~((1 << 15) - 1));
  }
}


int main(void) 
{
    int32_t q15 = 1 << 15;
    int32_t a_q15 = q15 * 0.5;
    int32_t b_q15 = a_q15 * -1.5;

    printf("%16d, %16d, %16d\n", q15, a_q15, b_q15);
    printf("%16x, %16x, %16x\n", q15, a_q15, b_q15);

    printf("%16d, %16d, %16d\n", q15Floor(q15), q15Floor(a_q15), q15Floor(b_q15));
    printf("%16x, %16x, %16x\n", q15Floor(q15), q15Floor(a_q15), q15Floor(b_q15));
    printf("%16d, %16d, %16d\n", q15Floor(q15) >> 15, q15Floor(a_q15) >> 15, q15Floor(b_q15) >> 15);
}