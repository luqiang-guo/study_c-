#include <iostream>

template<typename T>
bool is_type(void)
{
    return (std::is_same<T, float>::value || std::is_same<T, int32_t>::value);
}


int main()
{
    if(is_type<float>())
    {
        printf("float-->\n");
    }
    if(is_type<double>())
    {
        printf("double-->\n");
    }
    return 0;
}