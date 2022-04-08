#include <iostream>

template<typename T>
 T GetMaxVal() {
  uint16_t ret = 0x7bff;  // Decimal: 31743; Binary: 0 11110 1111111111
  return *(T*)&ret;
}

bool IsKernelSafeInt32(int64_t n) 
{ 
    return n <= GetMaxVal<int32_t>() / 2; 
}


int main(void)
{
    int32_t x = 0xff;
    if(IsKernelSafeInt32(x))
    {
        std::cout <<"is  32"<< std::endl;
    }
    else
    {
        std::cout <<"is  64"<< std::endl;
    }
    return 0;
}