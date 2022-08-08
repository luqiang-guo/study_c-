
#include <iostream>

// using namespace std;

// 模板函数 - 1个参数类型
template <class T>
T Max(T a, T b) 
{
    std::cout << "TemplateMax" <<std::endl; return 0;
}

// 模板函数 - 2个参数类型
template <class T, class T2>
T Max(T a, T2 b) 
{
    std::cout << "TemplateMax2" <<std::endl; return 0;
}

// 普通函数
double Max(double a, double b)
{
    std::cout << "MyMax" << std::endl;
    return 0;
}

int main() 
{
    int i=4, j=5;

    // 输出MyMax - 匹配普通函数
    Max( 1.2, 3.4 ); 

    //输出TemplateMax - 匹配参数一样的模板函
    Max( i, j );

    //输出TemplateMax2 - 匹配参数类型不同的模板函数
    Max( 1.2, 3 );   

    return 0;
}