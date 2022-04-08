#include <iostream>

// using namespace std;
template <typename T> 
class test;

template <typename T> 
class test
{
public:

    void test_a(T x) {  std::cout<< " template " << std::endl;}

    // T _x;
};

template <> 
class test<float>
{
public:

    void test_a(float x) {  std::cout<< " float " << std::endl;}

    // T _x;
};

int main() 
{
    float n = 5;
    
    test<float>  a;
    a.test_a(n);
    return 0;
}