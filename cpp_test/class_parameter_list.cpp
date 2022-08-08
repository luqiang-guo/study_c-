#include <iostream>

class A
{
public:
    A(int a):a_(a) {}

int a_;
};

class B
{
public:
    B(int a):a_(a) {}

A a_;
int b;
};

int main()
{
    A a{32};
    B b{0};
    float * t;
    std::cout << sizeof(t) << std::endl;

    std::cout << sizeof(A) << std::endl;
    std::cout << sizeof(B) << std::endl;

    return 0;    
}