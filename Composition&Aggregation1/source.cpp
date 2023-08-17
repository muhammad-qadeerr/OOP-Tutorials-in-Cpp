/*  FILE CONTAIN: Lecture 16,17
    - Gaddis book Page n0 867 onwords.
    - Composition/Aggregation
        - Relationship between various classes.  (HAS A Relationship)
        - Also called as Whole-Part Relationship.
        -i.e Circle has a Point.
        - Composite (Circle) , Composed (Point)
        - Life-Time Dependency (Construct and destroyed at the same time)
        - ClassRoom has a chairs, students, walls, PC etc etc.
        - Some composed classed have strong relations i.e life-time dependencies can be seem.
        - STRONG RELATIONSHIP --> COMPOSITION (HAS A)
            - Life time dependencies
            - No sharing of composed objects. i.e point can only be part of circle, no other class.
        - WEAK RELATIONSHIP --> AGGREGATION (HAS A)
            - No Life time dependencies  (Do not constructed and destroyed at the same time).
            - Sharing of composed objects.
            - Big Class(Aggregate), Small Class(Aggregated)
    - Depend upon problem statement and problem scope.
    - Order of Constructors and Destructors.
    - Use of member initialization list to use the functionality of Point Constructors (Order does'nt matter in member intitialization lists)
*/
#include <iostream>
#include <fstream>
#include <string>
#include "Point.cpp"
// #include "Circle.h"    // Won't work in VS code instead include Circle.cpp
#include "Circle.cpp"

using namespace std;
// class C; // Forward Declation of C as it is implemented after A so.. (It wasn't working in the lecture.)
class C
{
private:
public:
    C()
    {
        cout << "C's Constructor \n";
    }
    ~C()
    {
        cout << "C's Destructor \n";
    }
};
class A
{
private:
    C c; // It won't work without forward declaration.

public:
    A()
    {
        cout << "A's Constructor \n";
    }
    ~A()
    {
        cout << "A's Destructor \n";
    }
};
class B
{
private:
    A a1;
    C c2;

public:
    B()
    {
        cout << "B's Constructor \n";
    }
    ~B()
    {
        cout << "B's Destructor \n";
    }
};
int main()
{
    // Circle c1;
    Circle c2(10, 12, 11.5);

    // Circle arr[5];

    /* Circle *cp;
     cp = new Circle;

     cout << "---------------IN MAIN---------------" << endl;

     delete cp;
     cp = nullptr;*/

    //------------------------Checking the Sequence of Constructors and Destructors --------------------------------

    // B b1;
    // cout << "---------_IN MAIN_------------------\n";
    return 0;
}