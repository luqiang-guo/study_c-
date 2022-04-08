#include <iostream>
#include <chrono>
 
long fibonacci(unsigned n)
{
    if (n < 2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
 
int main()
{
    auto start = std::chrono::steady_clock::now();
    auto time1 = std::chrono::duration_cast<std::chrono::microseconds>(start).count();
    printf("time1 = %lf", time1);
    // std::cout << "f(42) = " << fibonacci(42) << '\n';
    auto end = std::chrono::steady_clock::now();
    auto time2 = std::chrono::duration_cast<std::chrono::microseconds>(end).count();
    printf("time2 = %lf", time2);
    std::chrono::duration<double> elapsed_seconds = end-start;
    // auto time  = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "elapsed time: " << elapsed_seconds.count() * 1000000 << "us\n";
}