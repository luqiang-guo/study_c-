#include <iostream>
#include <vector>
#include <string.h>

int main()
{
    int test[4] = {2,3,4,5};

    std::vector<int> dims0(test, test+4);
    
    std::vector<int> dims1(4);
    memcpy(dims1.data(), test, 4*sizeof(int));
    for(int i = 0; i< 4; i++)
    {
        printf("i = %d, %d \n", i, dims0[i]);
        printf("i = %d, %d \n", i, dims1[i]);
    }



    return 0;
}

#include<string.h>
#include<iostream>
#include<vector>

static void vector_1(benchmark::State& state)
{
int test[4]={2,3,4,5};
std::vector<int> dims0(test, test+4);
}
BENCHMARK(vector_1);

static void vector_2(benchmark::State& state)
{
  int test[4]={2,3,4,5};
  std::vector<int>dims1(4);
  memcpy(dims1.data(),test,4*sizeof(int));
}
BENCHMARK(vector_2);
