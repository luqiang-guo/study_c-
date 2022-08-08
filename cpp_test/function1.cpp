#include <iostream>
#include <functional>


void  test(void)
{
    std::cout << "test" << std::endl;
}

class vectorized
{
public:
    static void vec_init(void){ v1 = test;}
    static std::function<void(void)> v1;
};

std::function<void(void)> vectorized::v1;


void init()
{
    std::cout << "init ---->>" << std::endl;
    vectorized::vec_init();
}


namespace {                                                       
  struct Command_test {                            
    Command_test() { init();}                
  };                                                                
  Command_test var; 
}

int main(void)
{
    std::cout << "main--->" << std::endl;

    std::function< void(void) > p;

    p = test;

    auto fp = *(p.target<void(*)()>());


    printf("test is %p\n", test);
    printf("fp is %p\n", fp);

    vectorized::v1();
    auto vp = *(vectorized::v1.target<void(*)()>());
    printf("vp is %p\n", vp);
}