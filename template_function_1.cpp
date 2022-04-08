#include <iostream>

void test_s(float x, float y)
{
    std::cout<< "Float -->> : " << x + y << std::endl;
}

void test_d(double x, double y)
{
    std::cout<< "Double -->> : " << x + y << std::endl;
}

template<typename T> void test(T x, T y);

template<>
void test<float>(float x, float y)
{
    test_s(x, y);
}


template<>
void test<double>(double x, double y)
{
    test_d(x, y);
}

template <typename T>
void compute(T x, T y)
{
    test(x, y); 
    std::cout<< "compute -->> : "<<std::endl;
}

int main(void)
{
    float a = 0.3;
    float b = 0.2215;

    double x = 1.555555;
    double y = 2.6645456;


    compute(x, y);
    return 0;
}