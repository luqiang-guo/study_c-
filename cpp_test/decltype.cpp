#include <iostream>


int main(void) {
    using Test = decltype((int *){});

    printf("Test! \n");
    return 0;
}
