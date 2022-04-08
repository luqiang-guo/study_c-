#include <iostream>

using namespace std;

class A
{
public:
    virtual void foo()
    {
        cout<<"A::foo() is called"<<endl;
    }
};
class B:public A
{
public:
    void foo()
    {
        cout<<"B::foo() is called"<<endl;
    }
};
int main(void)
{
    A *a = new B();
    a->foo();  
    return 0;
}

// //函数指针写法

// typedef struct test_a
// {
//     void * p(void);
// }test_a;


// //B 注册指针


// void foo(void)
// {

// }



