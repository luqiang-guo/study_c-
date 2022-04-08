#include <iostream>
#include <vector>
#include<memory>



class A
{
public:
    A(){ std::cout << "creat A" << std::endl;}
};

int main()
{
    std::vector<std::shared_ptr<A>> test_a;
    // std::vector<std::shared_ptr<one::Tensor>> tensor_indices;
    return 0;
}