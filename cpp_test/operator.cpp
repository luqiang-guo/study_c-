#include <iostream>




class A
{
public: 
    A(int x): b(x){std::cout << "A() " << std::endl;}


    int operator=(int x)
    {
        b = x * b;
        return b;
    }

    int b;
};


int main(void)
{
    A a{3};

    a = 4;

    std::cout<< a.b<< std::endl; 
    return 0;
}