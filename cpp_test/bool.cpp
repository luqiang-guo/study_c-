#include <iostream>
#include <vector>

int main()
{
    printf("sizeof(bool) = %d \n", sizeof(bool));
    printf("sizeof(char) = %d \n", sizeof(char));

    std::vector<bool> test {1,1,1,1};
    printf("test[0] = %d \n", test[0] );
    printf("test[1] = %d \n", test[1] );
    test[2] = 0;
    printf("test[2] = %d \n", test[2] );

    int8_t v = -127;
    bool a = (bool)v;
    uint8_t v1 = (uint8_t)(a + a);

    printf("int8_t v = %x \n", v);
    printf("bool a = %x \n", a);
    printf("uint8_t v1 = %x \n", v1);
    printf("bool a = %x \n", a + a);
    return 0;
}