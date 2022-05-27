#include <iostream>
#include <vector>



int main(void)
{
    std::vector<int> size {-1,1,2,3};

    // size.erase(size.begin());

    std::vector<int> copy(size.begin()+1, size.end());

    for(int i=0; i < copy.size();i++)
    {
        printf("%d \n", copy[i]);
    }
    return 0;
}