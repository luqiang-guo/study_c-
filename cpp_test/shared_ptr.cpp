#include <iostream>
#include <vector>
#include<memory>

class B;
class A
{
public:
 A(  ) : m_sptrB(nullptr) { };
 ~A( )
 {
  std::cout<<" A is destroyed"<<std::endl;
 }
 std::shared_ptr<B> m_sptrB;
};
class B
{
public:
 B(  ) : m_sptrA(nullptr) { };
 ~B( )
 {
  std::cout<<" B is destroyed"<<std::endl;
 }
 std::shared_ptr<A> m_sptrA;
};
//***********************************************************
int main()
{
 std::shared_ptr<B> sptrB( new B );
 std::shared_ptr<A> sptrA( new A );
 sptrB->m_sptrA = sptrA;
 sptrA->m_sptrB = sptrB;
 return 0;
}