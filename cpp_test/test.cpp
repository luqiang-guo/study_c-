#include <iostream>
#include <string>
#include <string.h>
using namespace std;

void strDel(char *s1, const char *s2)
{

    size_t l1 = strlen(s1);
    size_t l2 = strlen(s2);

    size_t k = 0;

    for(size_t i = 0; i < l1; i++)
    {
        for(size_t j = 0; j < l2; j++)
        {
            if(s1[i] == s2[j])
            {
                break;
            }
        }
        if(k == l2) 
        {
            s1[k++] = s1[i];
        }
    }
    s1[k] = 0;
}

int main() {
    char s1[16] = "geaabse";
    char s2[4] = "ea";

    strDel(s1, s2);

    printf("%s\n", s1);
}