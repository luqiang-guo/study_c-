#include <iostream>




int main()
{
    // int a[128];

    // void * p  =  a;

    // float * p1 = reinterpret_cast<float *>(p);

    // const void  * q = a;

    // const float * q1 = reinterpret_cast<const float *>(q);

    // float * t  = reinterpret_cast<float *>( const_cast<void *>(q) );


    double f = 3.1415926535626;

    float r = static_cast<float>(f);
    printf("float = %f , f = %f\n", r, f);

    int x = 383;
    int8_t i = x;
    printf("int8_t = %d \n", i);



}