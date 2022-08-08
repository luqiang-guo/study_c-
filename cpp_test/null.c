#include <stdio.h>

int& null(int * a)
{
    return *a;
}

int main(void)
{
    null(0);

    // int *b =0;

    // int a = *b;

    return 0;
}