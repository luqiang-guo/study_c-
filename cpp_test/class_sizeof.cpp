#include <iostream>


class A {
  public:
    A() {}
    virtual ~A()=0;
  protected:
    virtual void funcA()=0;
  private:
    int a = 0;
};
class B: virtual A {
  protected:
    virtual void funcA() override {}
    virtual void funcB() {}
  private:
    long b = 0;
    int score = 0;
};
class C: virtual A {
  protected:
    virtual void funcA() override {}
    void funcC() {}
  private:
    float c = 0.0f;
    double* score = nullptr;
};
class D:   B,  C {
  protected:
    virtual void funcA() override {}
    virtual void funcB() override {}
  private:
    unsigned char d = 0x0;
    static unsigned char* p;
};


int main()
{
    // unsigned char* D::p=nullptr;

    std::cout << sizeof(A) << std::endl;
    std::cout << sizeof(B) << std::endl;
    std::cout << sizeof(C) << std::endl;
    std::cout << sizeof(D) << std::endl;

}
