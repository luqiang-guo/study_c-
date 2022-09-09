#include <iostream>
#include <cmath>

int main (void) 
{
    float fa = 0.5f;
    float fb = 0.1f;
    float fc = 0.8f;
    float fd = -0.5f;
    float fe = -0.1f;
    float ff = -0.8f;

    int ia = (int)fa;
    int sa = static_cast<int>(fa);
    int da = (int)std::floor(fa);

    int ib = (int)fb;
    int sb = static_cast<int>(fb);
    int db = (int)std::floor(fb);

    int ic = (int)fc;
    int sc = static_cast<int>(fc);
    int dc = (int)std::floor(fc);

    int id =              (int)fd;
    int sd =  static_cast<int>(fd);
    int dd =   (int)std::floor(fd);

    int ie =              (int)fe;
    int se =  static_cast<int>(fe);
    int de =   (int)std::floor(fe);

    int i_f =              (int)ff;
    int sf =  static_cast<int>(ff);
    int df =   (int)std::floor(ff);


    return 0;
}