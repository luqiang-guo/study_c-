#include <iostream>
#include <stdio.h>


int main(void)
{
    int a = 10;

    int & b = a;

    printf("a = %p,\nb = %p \n", &a, &b);
    return 0;

}