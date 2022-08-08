#include <iostream>
#include <bitset>
#include <stdlib.h>

int main(void) {
    size_t num = 32;

    try {
        void* data = malloc(num/8);

        std::bitset<8>* bitData = (std::bitset<8>*)data;

        for (size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < 8; j++) {
                if (j % 3 == 0) {
                    bitData->set(j);
                }
            }
            bitData++;
        }

        free(data);
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}