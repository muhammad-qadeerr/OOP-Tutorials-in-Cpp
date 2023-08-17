#include <iostream>
#include "Circle.h"

using namespace std;

Circle::Circle() : center(0, 0) // used member initialization list call Point Constructors
{
    cout << "Circle Default Constructor Called!!" << endl;
    radius = 1.0;
    // center.setX(0); // Public member function of point class can be accessed by circle class
    // center.setX(0); // These two line are use less as point already set these values to 0.
}
Circle::~Circle()
{
    cout << "Circle Destructor Called!!" << endl;
}
// Use member initialization list to initialize the Point Object (Center) when Point Overloaed Constructor wasn't written.
// Order doesn't mattter in member initialization list but order while declaration in class matters.
Circle::Circle(int a, int b, double c) : center(a, b), radius(c)
{
    cout << "Circle Overloaded Constructor Called !!!" << endl;
    // center.setX(a);
    // center.setY(b);
    // radius = c;
}