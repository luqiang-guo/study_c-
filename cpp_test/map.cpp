#include <iostream>
#include <vector>
#include <map>
#include <any>


int main(void) {

    float step = 0.1;
    std::vector<int64_t> vec{1,2,3};
    std::map<std::string, std::any> test {{"test", step}, {"vector", vec}};

    auto iter = test.find("vector");

    if(iter == test.end()) {
        printf("error -----> \n");
    }
    printf("find it -----> \n");
    // printf("%f \n", iter->)
    return 0;
}