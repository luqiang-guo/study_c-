#include <iostream>
#include <functional>


struct test
{
    static int a;
};

int test::a;


int main()
{
    test::a = 1;
}