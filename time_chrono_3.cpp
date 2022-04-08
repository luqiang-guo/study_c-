#include <iostream>
#include <chrono>
#include <sys/time.h>
 
int main()
{

    printf("start = %ld \n", std::chrono::steady_clock::now().time_since_epoch().count());

    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("%s:%d , time: %ld s, %ld us. \n", __FILE__, __LINE__, tv.tv_sec, tv.tv_usec);

    struct timeval tv1;
    struct timeval tv2;
    gettimeofday(&tv1, NULL);
    printf("start = %ld \n", std::chrono::steady_clock::now().time_since_epoch().count());

    gettimeofday(&tv2, NULL);
    printf("time: %ld s, %ld us. \n", tv1.tv_sec, tv1.tv_usec);
    printf("time: %ld s, %ld us. \n", tv2.tv_sec, tv2.tv_usec);

    
}
