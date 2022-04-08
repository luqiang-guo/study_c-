#include <iostream>
#include <memory>



int main(void)
{   
    // 两次分配内存
    std::shared_ptr<int> p1(new int());

    std::cout << "p1.use_count = " <<p1.use_count() << std::endl;

    // 一次性分配内存
    std::shared_ptr<int> p2 = std::make_shared<int>();

}