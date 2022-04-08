#include <iostream>

enum CalculateType : int {
  test = 0,
  onednn = 1,
};

class base
{
public:
  base(){ b = 0; std::cout << "base" << std::endl; }

  int b;
};

template<typename T, CalculateType calculate_type, typename Enable = void> 
class  A ;

template<typename T, CalculateType calculate_type>
class  A   <T, calculate_type , typename std::enable_if<calculate_type == CalculateType::onednn>::type> : public base
{
public :
    A(T i){ std::cout << i << " onednn "<< std::endl;}
};


template<typename T, CalculateType calculate_type>
class  A   <T, calculate_type , typename std::enable_if<calculate_type == CalculateType::test>::type> : public base
{
public :
    A(T i){ std::cout << i << " test "<< std::endl;}
};

int main()
{
    A<float, CalculateType::test> a {1};

    return 0;
}
