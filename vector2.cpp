#include <iostream>
#include <vector>


int main(void)
{
    std::vector<int> dim(8,0);
    printf("dim.size = %d, \n", dim.size());
    dim.resize(1);
    printf("dim.size = %d\n", dim.size());
}