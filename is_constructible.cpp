// C++ program to illustrate 
// std::is_constructible example 
#include <bits/stdc++.h> 
#include <type_traits> 
using namespace std; 
  
// Declare structures 
struct A { 
}; 
  
struct T { 
    T(int, int){}; 
}; 
  
// Driver Code 
int main() 
{ 
    cout << std::boolalpha; 
  
    // Check if <int> is 
    // constructible or not 
    cout << "int:"
         << is_constructible<int>::value 
         << endl; 
  
    // Check if <int, float> is 
    // constructible or not 
    cout << "int(float):"
         << is_constructible<int, float>::value 
         << endl; 
  
    // Check if <int, float, float> is 
    // constructible or not 
    cout << "int(float, float):"
         << is_constructible<int, float, float>::value 
         << endl; 
  
    // Check if struct T is 
    // constructible or not 
    cout << "T:"
         << is_constructible<T>::value 
         << endl; 
  
    // Check if struct <T, int> is 
    // constructible or not 
    cout << "T(int):"
         << is_constructible<T, int>::value 
         << endl; 
  
    // Check if struct <T, int, int> is 
    // constructible or not 
    cout << "T(int, int):"
         << is_constructible<T, int, int>::value 
         << endl; 
    return 0; 
}