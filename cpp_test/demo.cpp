
int8_t test_int8_t(int8_t a)
{
    return a;
}
int16_t test_int8_t(int16_t a)
{
    return a;
}
int32_t test_int32_t(int32_t a)
{
    return a;
}
float test_float(float a)
{
    return a;
}
double test_double(double a)
{
    return a;
}

template<typename T>
T test(T a)
{
    return a;
}



int test()
{
    device1 = device1()
    if(!device1)
    {
        goto error1;
    }

    device2 = device2()
    if(!device1)
    {
        goto error2;
    }

    device3 = device3()
    if(!device1)
    {
        goto error3;
    }

    return 0;
error3 :
// *****
error2 :
// *****
error1 :
// *****

}




