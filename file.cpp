#include <iostream>
#include <string.h>
#include <fstream>

int main(void)
{
    std::ofstream test("test.txt", std::ios::binary);

    char tmp[1024];
    // sprintf(tmp, "{\"name\": \"%d\", \"ph\": \"B\", \"pid\": \"NOVA-0\", \"tid\": \"nova\", \"ts\": %d},\n{\"name\": \"%d\", \"ph\": \"E\", \"pid\": \"NOVA-0\", \"tid\": \"nova\", \"ts\": %d},\n", 1,2,3,4);
    // test.write(tmp, strlen(tmp) + 1); 
    sprintf(tmp,"test = %d\n", 1);
    printf("str = %s, len = %ld\n", tmp, strlen(tmp));
    test.write(tmp, strlen(tmp)); 
    return 0;
}
