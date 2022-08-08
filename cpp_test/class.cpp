#include <iostream>

class  Base
{
public:
    int base;
};

class  A : public Base
{
public:
    float *x, *y;

    void Print()
    {
        std::cout<< x << "," << y << std::endl;
    }
};

class B : public A
{
    int a, b;
};

int main()
{
    A e;

    float * t;
    std::cout << sizeof(t) << std::endl;

    std::cout << sizeof(A) << std::endl;
    std::cout << sizeof(B) << std::endl;
    std::cout << e.x << std::endl;

    // e.Print();

    return 0;    
}