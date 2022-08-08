#include <iostream>
#define mu 1

#if mu == 0
#else
#error mu = 0
#endif

int main(void)
{
    return 0;
}