#include <iostream>



int main(void) 
{
    int8_t v = 65;
    float mean = 512.0f;
    float var = 1.0f;

    float out = (v - mean)/var;
    std::cout << out << std::endl;
    return 0;
}