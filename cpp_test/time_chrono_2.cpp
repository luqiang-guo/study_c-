#include <iostream>
#include <chrono>
 
int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(start);
    std::cout << "Now is: " << ctime(&time) << std::endl;
    // auto time1 = std::chrono::duration_cast<std::chrono::microseconds>(start).count();
    // printf("time1 = %lf", time1);

    auto end = std::chrono::high_resolution_clock::now();
    auto time2 = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
    // printf("time2 = %lf", time2);
    // std::chrono::duration<double> elapsed_seconds = end-start;
    // // auto time  = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    // std::cout << "elapsed time: " << elapsed_seconds.count() * 1000000 << "us\n";
}
    // auto now = chrono::system_clock::now();
    // time_t time = chrono::system_clock::to_time_t(now);
    // cout << "Now is: " << ctime(&time) << endl;