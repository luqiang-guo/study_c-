#include <iostream>
#include <cstdint>


int main()
{

    uint64_t a = 0x7fffffffffffffff;

    int64_t b;

    b = a;

    std::cout << " a : " << a << std::endl;
    std::cout << " b : " << b << std::endl;

}