#include <iostream>

class A
{
public:
    A(int i)
        :a{i}
    {
        std::cout << "init A" << std::endl;
    }

    int a;
};


class M
{
public:
    M(A a)
    {
        std::cout << "init M" << std::endl;
        std::cout << a.a << std::endl;
        m = a.a;
    }

    int m;
};


int main(void)
{
    A a(1);
    M b = a;
    // std::cout << "________________________" << std::endl;
    M n(a);
    M m{a};

    return 0;
}