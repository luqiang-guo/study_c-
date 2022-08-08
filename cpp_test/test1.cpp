#include <iostream>

class A {
 public:
  A(int a) : a_(a) {}
  A(const A& other) : a_(other.a_) {
    std::cout << "Copy construct" << std::endl;
  }
  A(A&&) { std::cout << "move " << std::endl; };

  int a() const { return a_; }

    A& operator=(const A& other) { 
        std::cout << "Copy vlaue" << std::endl;
        if(this==&other)
        {
        return *this;
        }
        a_ = other.a_;
        return * this;
    }

    void set(int n){ a_= n;}
 private:
  int a_;
};

A MakeAInternal() {
  return A(1);
}

A MakeA() {
//   const A& a = MakeAInternal
  A a = MakeAInternal();
  a.set(1212);
  return a;
}

int main() {
  auto a = MakeA();
  std::cout << "a 2 = " << a.a() << std::endl;
  return 0;
}
