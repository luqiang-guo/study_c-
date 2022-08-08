#include <iostream>
#include <string>

class A {
public: 
    A() {}

    virtual void test() = 0;

    const std::string name;
};


class B : public A {
public:
    B() {}

    void test() override { printf("test %s\n", name.c_str());}
};

// const  std::string B::name = "B !!";

int main () {

    B b;

    b.test();
    return 0;
}