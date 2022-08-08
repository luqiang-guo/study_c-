#include <iostream>

class A;

class A {
public:
    static const int c=5;
};

int b= A::c; 

int main(void)
{
    std::cout << "test---->" << std::endl;
    return 0;
}