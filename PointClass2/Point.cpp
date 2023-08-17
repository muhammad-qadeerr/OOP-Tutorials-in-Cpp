#include <iostream>
#include <string>
#include "Point.h"

using namespace std;

void Point::setX(int val)
{
    x = val;
}
void Point::setY(int val)
{
    y = val;
}

Point::Point()
{
    cout << "Default Constructor Called!!" << endl;
    x = 0;
    y = 0;
}
//- Conversion Constructoor from int to a point Conversion.
// Int -------> Point.

Point::Point(int z)
{
    // cout << "Overloaded Contructor Called!! (1 Parameters)" << endl;
    cout << "Conversion Constructor Called!!" << endl;
    x = z;
    y = z;
}
Point ::Point(int a, int b)
{
    cout << "Overloaded Contructor Called!! (2 Parameters)" << endl;
    x = a;
    y = b;
}
Point ::~Point()
{
    cout << "Destructor Called!! " << endl;
}
Point::Point(const Point &orig) : x(orig.x), y(orig.y)
{

    cout << "Copy Constructor Called!!!" << endl;
    // x = orig.x;
    // y = orig.y;
}
/*int Point::getX() const
{

    return x;
}
int Point::getY() const
{

    return y;
}*/
void Point::displayPoint() const
{
    cout << "(" << x << ", " << y << ")\n";
    // cout << "(" << getX() << ", " << getY() << ")\n"; // ERROR: Non constant functions can't be called in constant function
}
void Point::setCoordinates(int v1, int v2)
{
    x = v1;
    y = v2;

    // setX(v1);
    // setY(v2);
}
Point Point ::add(const Point &p) const
{
    Point sum;
    sum.x = x + p.x;
    sum.y = y + p.y;
    return sum;
}
Point Point ::operator+(const Point &p) const
{
    Point sum;
    sum.x = x + p.x;
    sum.y = y + p.y;
    return sum;
}
// void Point::operator+=(const Point &p) // for p2 += p1
//   For Cascaded use i.e p3 += p2 += p1;
Point &Point::operator+=(const Point &p)
{
    x += p.x;
    y += p.y;
    return *this;
}
Point Point::operator+(int n) const
{
    Point sum1;
    sum1.x = x + n;
    sum1.y = y + n;
    return sum1;
}
bool Point::operator==(const Point &rhs) const
{
    if (x == rhs.x && y == rhs.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Point ::operator!=(const Point &rhs) const
{
    if (*this == rhs)
    {
        return false;
    }
    else
    {
        return true;
    }
    // if (x == rhs.x && y == rhs.y)
    // {
    //     return false;
    // }
    // else
    // {
    //     return true;
    // }
}
// void Point::operator++()
// Pre- Increament Version.
Point &Point::operator++()
{
    x = x + 1;
    y = y + 1;
    return *this;
}
// Post- Increament Version.
Point Point::operator++(int)
{
    Point temp = *this; // temp created through copy constructor
    x = x + 1;
    y = y + 1;
    return temp;
}
//--------------------------------------Lec 13----------------------------------------------------------------------------------
Point Point ::operator-() const
{
    Point temp;
    temp.x = -x;
    temp.y = -y;
    return temp;
}
// void Point ::operator=(const Point &rhs) // works for p1 = p2;
// {
//     cout << "Assignment Operator Called!" << endl;
//     x = rhs.x;
//     y = rhs.y;
// }

// For Cascade assignment
const Point &Point ::operator=(const Point &rhs)
{
    cout << "Cascaded Assignment Operator Called!" << endl;
    x = rhs.x;
    y = rhs.y;
    return *this;
}
// --------------------------------------------Lec 14 ----------------------------------------------------
// void Point::operator<<(ostream &o)
// {
//     o << "(" << x << " , " << y << ")" << endl;
// }

int &Point::operator[](char i)

{
    if (i == 'x')
    {
        return x;
    }
    else if (i == 'y')
    {
        return y;
    }
}

// ------------------------------Lec 15 (3-11-2020)-----------------------

Point Point ::operator()(int a, int b) const
{
    Point temp(*this); // Making copy of current object. (By copy Constructor)

    temp.x += a;
    temp.y += b;

    return temp;
}
Point ::operator int()
{
    return x + y;
}
Point ::operator string() const
{
    string str = "(";
    str += to_string(x);
    str += ",";
    str += to_string(y);
    str += ")";
    return str;
}