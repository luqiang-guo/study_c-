#include <iostream>
#include <math.h>
#include <iomanip>



int main(void)
{
    double t1, t2, var, y1, y2;

    double x1 = -1.07859517;
    double x2 = -1.08569756;

    double mean = (x1+x2)*0.5;
    
    t1 = x1 - mean;
    t2 = x2 - mean;

    var = (t1 * t1 + t2 * t2) * 0.5;

    var = sqrt(var  + 0.00001);

    y1 = t1 / var;
    y2 = t2 / var;

    std::cout << "mean = " << mean << std::endl;
    std::cout << t1 << " " << t2 << std::endl;
    std::cout << "var = " << var << std::endl;
    
    std::cout << std::fixed << std::setprecision(20) << y1 << " " << y2 << std::endl;


    return 0;
}