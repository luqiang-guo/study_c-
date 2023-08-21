#include <stdio.h>



int main(void) {
    int i = 0;
    int n = 13;

    for(; i <= n - 4; i += 1) {
        printf("i = %d \n", i);
    }
    printf("-->i = %d \n", i);
    return 0;
}