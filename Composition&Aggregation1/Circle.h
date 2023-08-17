#ifndef CIRCLE_H
#define CIRCEL_H

#include "Point.h"
class Circle
{
private:
    Point center; // Circle is Compsed of Point (Composition)
    double radius;

    // Let say we have a class Style.

    // Style *sp;  it is aggregation but it can be composition when we allocate a new memory with the help of this pointer in constructor.
    // We will check implementation of all member functions to check whether it is composition or aggregation.

public:
    Circle();
    ~Circle();
    Circle(int, int, double); // Circle overloaded constructor will have x,y, (From Point) and Radius as a parameter.
};
#endif