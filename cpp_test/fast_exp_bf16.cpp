#include <cstdint>
#include <iostream>
#include <cmath>

constexpr float LOG2EF = 1.44269504088896341;
constexpr float LN2 = 0.69314718056;
constexpr uint32_t F_MASK = 0x807FFFFF;

//  e^x = 2^i * 2^f, f in [-½, ½],
//  e^x = 2^i * e^f, f in [-½log 2, ½log 2]
//  i = floor (log2(e) * x),  f = i 
//  e^f => x + 1
float bf16_exp_int(int32_t x)
{
    // i = LOG2EF * x
    // int_i = int(i + 0.5)
    float i = LOG2EF * x;
    int32_t int_i = std::floor(i);

    float f = x - int_i * LN2;
    float ef = f + 1;

    uint32_t ef_b = *((uint32_t *)(&ef)) & F_MASK;
    int_i = ((int_i + 127) << 23) & (~F_MASK);
    ef_b = ef_b | int_i;

    return *((float *)&ef_b);
}

inline uint32_t float_2_bin(float x)
{
    return *((uint32_t *)&x);
}

inline float bin_2_float(uint32_t x)
{
    return *((float *)&x);
}

void diff_print(float a, float b)
{
    printf("float32 diff : e^x = %.12f, bf16_exp_int = %.12f\n", a, b);
    float bf_a = bin_2_float(float_2_bin(a) & (~0xffff));
    float bf_b = bin_2_float(float_2_bin(b) & (~0xffff));
    printf("bfloat16 diff : e^x = %.12f, bf16_exp_int = %.12f\n", bf_a, bf_b);
}

int main(void) {

    for (int32_t x = -30; x <= 88; x++)
    {
        printf("------------- %d -----------\n", x);
        diff_print(std::exp(x), bf16_exp_int(x));
    }
}