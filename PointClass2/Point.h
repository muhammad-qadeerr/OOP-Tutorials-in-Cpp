#include <iostream>
#include <string>
#ifndef POINT_H // Preprocessor Directives
#define POINT_H // These statements used as a guard to prevent point class to use again.
class Point
{
private:
    int x;
    int y;

public:
    Point();

    Point(int, int);

    // Point(int); // Overloaded Constructor for one parameter.
    explicit Point(int);
    ~Point();
    void setX(int);
    void setY(int);
    void setCoordinates(int, int);
    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }

    void displayPoint() const;
    Point(const Point &);

    Point add(const Point &) const;
    // Operator Overloading

    Point operator+(const Point &) const;
    // void operator+=(const Point &);
    //  For Cascaed use i.e p3 += p2 += p1;
    Point &operator+=(const Point &); // returning by referece to avoid making copy.
    // Operator to add int to an object.
    Point operator+(int) const;

    bool operator==(const Point &) const;
    bool operator!=(const Point &) const;
    // Unary Operator Overloading

    // void Point::operator++();  // can't do p4 = ++p3; with this return type.
    Point &operator++();   // can do p4 = ++p3; with this
    Point operator++(int); // Post Increament Version.  (No reference bcz returning same object.)
    //----------------------------------------Lec 13---------------------------------------------------

    Point operator-() const;

    friend Point operator+(int, const Point &); // Making that global function as friend.

    // void operator=(const Point &); // works for p1 = p2;

    // for cascaded assignment
    const Point &operator=(const Point &); // constant refernece to avoid illegal assignment from left to right i.e (p1 = p2) = p3;

    //---------------------------------Lec 14 ------------------------------------------------------------

    // void operator<<(ostream &);
    friend ostream &operator<<(ostream &, const Point &);
    friend istream &operator>>(istream &, Point &);

    // Overloading Index Operator

    // int operator[](char);

    // --------------------------Lec 15 (3-11-2020)---------------------------------
    int &operator[](char); // return reference so that it can be used on both sides of object.

    // FUNCTION CALL OPERATOR    ()

    Point operator()(int, int) const;

    // CONVERSION OPERATOR.

    operator int(); // no Datatype,
    operator string() const;
    // TO DO:
    // operator char *() const;
};
#endif