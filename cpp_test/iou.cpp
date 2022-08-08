#include <iostream>
#include <cmath>
#include <cstdlib>

class Rectangle
{

public:
    Rectangle(float x1, float y1, float x2, float y2)
    {
        if(x2 >= x1)
        {
            _x1 = x1;
            _x2 = x2;
        }

        if(y2 >= y1)
        {
            _y1 = y1;
            _y2 = y2;
        }
            
        std::cout<< "Rectangle x1 y1 x2 y2"<< std::endl;
    }
    
    Rectangle()
    :_x1(0),_y1(0), _x2(0), _y2(0){std::cout<< "Rectangle "<< std::endl;}

    float area() {return std::abs((_x2 - _x1)*(_y2 - _y1));}

    friend float CheckIntersection(Rectangle& x, Rectangle& y);

private:

    float _x1, _y1, _x2, _y2;

};


float CheckIntersection(Rectangle& x, Rectangle& y)
{
    float x_overlap = std::min(y._x2, x._x2) - std::max(y._x1, x._x1);

    float y_overlap = std::min(y._y2, x._y2) - std::max(y._y1, x._y1);
    if (x_overlap <=  0 || y_overlap <= 0)
        return 0;
    return x_overlap * y_overlap;
}



int main()
{
    Rectangle a(1.0, 1.0, 4.0, 4.0);
    Rectangle b(2.0, 0.0, 5.0, 5.0);

    float tmp = CheckIntersection(a , b);


    std::cout << tmp << std::endl;

    return 0;

}