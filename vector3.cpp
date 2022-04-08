#include <iostream>
#include <vector>

#define SIZE 512

void test(char * workspace)
{
    char* crop_buf = nullptr;

    
    if(!workspace)
    {
        std::vector<char> tmp_buf(SIZE);
        std::cout<< "vector -->" << std::endl;
        crop_buf = tmp_buf.data();
    }
    else
    {
        std::cout<< "nothing todo !!!" << std::endl;
        crop_buf = workspace;
    }

    crop_buf[0] = 0;
    crop_buf[511] = 0;
}

int main(void)
{
    char * tmp = (char *)malloc(SIZE);
    test(tmp);
    test(NULL);
}