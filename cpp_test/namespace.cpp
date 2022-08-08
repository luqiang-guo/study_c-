#include <iostream>



namespace mu1
{
    int a1 = 0;


    void test_print(void)
    {
        std::cout << a1++ << std::endl;
    }

namespace test
{


    void test_print2(void)
    {
        std::cout << a1++ << std::endl;
    }
}
}

int main()
{
    mu1::test_print();
    mu1::test_print();
    mu1::test_print();
    mu1::test_print();
    mu1::test::test_print2();
    mu1::test::test_print2();
    mu1::test::test_print2();

}



