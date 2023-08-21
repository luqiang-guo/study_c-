#include <iostream>
#include <cmath>

int main(void)
{
    float a = 0;

    uint32_t * p = (uint32_t*)&a;
    *p = 0x3f0e472c;

    float b = std::exp(a);

    printf("%x\n", *((uint32_t*)&b));
}

