#include <stdio.h>
#include <stdlib.h>

#define M 5
#define N 5

int main(void)
{
    int [][5] a = malloc(M*N*sizeof(int));

    a[2][3] =2;

    return 0;
}