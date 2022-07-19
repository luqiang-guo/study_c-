#include <iostream>
#include <map>
#include <any>


int main(void) {

    float step = 0.1;
    std::map<std::string, std::any> test {{"test", step}};

    auto iter = test.find("test");

    if(iter == test.end()) {
        printf("error -----> \n");
    }
    printf("find it -----> \n");
    // printf("%f \n", iter->)
    return 0;
}