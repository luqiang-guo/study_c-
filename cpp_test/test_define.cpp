#include <stdio.h>

#define TBB 1
#define OMP 2

int main(void)
{

#if MU == TBB
    printf("TBB \n");
#else 
    printf("OMP \n");
#endif
}