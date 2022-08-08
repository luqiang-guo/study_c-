#include <cstdint>
#include <iostream>




int main(void)
{
    int8_t  a = -111;   // 0x91
    
    int8_t  b = -110;   // 0x92


    int8_t  c = a + b;

    printf("a = %x, b = %x, c = %x \n", (uint8_t)a, (uint8_t)b, (uint8_t)c);
    return 0;
    
}