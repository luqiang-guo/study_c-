#include <iostream>


template <bool, typename T=void>
struct mu_enable_if {
};

template <typename T>
struct mu_enable_if<true, T> {
  using type = T;
};

template <typename T, typename Enable=void>
struct check;

template <typename T>
struct check<T, typename mu_enable_if<T::value>::type> {
  static constexpr bool value = T::value;
}; 

struct A
{
  static constexpr bool value = true;
};



int main(void)
{
  check<A> test;
}
