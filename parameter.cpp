#include <iostream>



int test(int * x, int *y, int *o, size_t len = 16)
{
    for(size_t i = 0; i < len; i++)
    {
        o[i] = x[i] + y[i];
    }
}


int main(void)
{
    int x[16], y[16], out[16];
    
    test(x, y, out);
}