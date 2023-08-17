#ifndef CIRCLE_H
#define CIRCEL_H

#include "Point.h"
#include "Test.h"
class Circle
{
private:
    Point center; // Circle is Composed of Point (Composition)
    double radius;
    Test t;

public:
    Circle();
    ~Circle();
    Circle(int, int, double, int, int);
    // Copy Constructor of Cricle class.
    Circle(const Circle &);
    // Assignment operator of circle class.
    const Circle &operator=(const Circle &);
};
#endif