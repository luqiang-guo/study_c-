#include <iostream>
#include <vector>
void test0(std::vector<int*>& v) {
    *v[0] = 2;
}

void test1(const std::vector<int*>& v) {
    *v[0] = 3;
}

void test2(const std::vector<const int*>& v) {
    *v[0] = 3;
}

int main(void) 
{
    int a = 10;

    std::vector<int *> v0 {&a};
    test0(v0);

    const std::vector<int *> v1 {&a};
    test1(v1);

}

