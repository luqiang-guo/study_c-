#include <iostream>

#define cb(i) "fmla v" #i ".4s, v" #i ".4s, v" #i ".4s\n"
#define test(i) "test" #i "_test_"
#define test1 "test" "_" "111"

int main(void) {
    printf("%s", cb(0));
    printf("%s \n", test(0));
    printf("%s \n", test1);
    printf("%s \n", "1_" "2_" "3_" "4_");
    return 0;
}