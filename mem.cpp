#include <iostream>

class A
{
public:

    A(){ std::cout << "A()" << std::endl; }
    A(int i):a(i) { std::cout << "A(i)" << std::endl; }
    ~A(){ std::cout << "~A()" << std::endl;}


    int a;
};

void print(A t)
{
    std::cout << t.a << std::endl;
}

int main(void)
{
    A a= 1;
    print(a);

    a.a =4;
    print(a);
}