#include <iostream>
#include <functional>

class test
{
public:
    test(){}

    int a,b,c,d;
};

void func(void)
{
    std::cout <<"test" << std::endl;
}

int main(void)
{

    test a{};
    std::function<void(void)> p;
    std::cout <<"a address = " << std::addressof(a) << std::endl;
    std::cout <<"p address = " << std::addressof(p) << std::endl;
    p = func;
    std::cout <<"p address = " << std::addressof(p) << std::endl;
    // std::cout <<std::addressof(a) << std::endl;

    return 0;
}