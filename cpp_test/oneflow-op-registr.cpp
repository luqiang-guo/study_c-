// Type your code here, or load an example.
#include <iostream>
#include <map>
#include <string>

class A
{
public:
	A() { static int idx = 0; std::cout << "A:" << idx++ <<std::endl; }
	~A() { static int idx = 0; std::cout << "~A:" << idx++ << std::endl; }

	A& Name(const std::string& name) { return *this; };
};

class C
{
public:
	static C& Get() { static C c; return c; }
	A& Check(const std::string& name) 
    { 
        return A().Name("test"); 
    }
	void Register(A a) { std::cout << "C register" << std::endl; }
	std::map<std::string, A> data;
};

class B
{
public:
	B(A& a) 
    { 
        std::cout << "a addr=" << &a<< std::endl; 
        C::Get();  
        static int idx = 0; 
        std::cout << "B:" << idx++ << std::endl; 
    }
	~B() { static int idx = 0; std::cout << "~B:" << idx++ << std::endl; }
};

static B b = C::Get().Check("aa");

int main()
{
    std::cout<<"test ----->" <<std::endl;
}