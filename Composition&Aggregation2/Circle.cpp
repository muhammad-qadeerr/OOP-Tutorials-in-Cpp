#include <iostream>
#include "Circle.h"

using namespace std;

Circle::Circle() : center(0, 0), t(11, 12) // It will call test default constructor otherwise automatically called.
{
    cout << "Circle Default Constructor Called!!" << endl;
    radius = 1.0;
}
Circle::~Circle()
{
    cout << "Circle Destructor Called!!" << endl;
}
Circle::Circle(int a, int b, double c, int d, int e) : center(a, b), radius(c), t(d, e)
{
    cout << "Circle Overloaded Constructor Called !!!" << endl;
    // center.setX(a);
    // center.setY(b);
    // radius = c;
}
Circle::Circle(const Circle &orig) : center(orig.center), radius(orig.radius), t(orig.t)
{
    cout << "Circle COPY CONSTYRCTOR Called!!" << endl;
}

const Circle &Circle ::operator=(const Circle &rhs)
{
    cout << "Circle  =   Operator called!!" << endl;
    if (this == &rhs)
    {
        return *this;
    }
    else
    {
        t = rhs.t; // Here calling assignment operator of Test.
        radius = rhs.radius;
        center = rhs.center; // Here calling assignment operator of Point.
    }
}
