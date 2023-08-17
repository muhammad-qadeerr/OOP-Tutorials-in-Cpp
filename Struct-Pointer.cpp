#include <iostream>
using namespace std;

struct twoVals
{
    int num;
    int *ptr;
};

struct Point // Point takes 8 byte in the memory.
{
    int x;
    int y;
};
struct Circle // Nested Structure
{
    Point center;
    double radius;
};

void displayPoint(const Point &p) // Pass by reference - no COPY is created.
                                  // Parameters are Local Variables of the function.
{
    // cout << "The Address of P in display function is: " << &p << endl;
    cout << "(" << p.x << "," << p.y << ")" << endl;
    // p.x = 0;
    // p.y = 0; // Value will modified after function call as it is being called by reference.
}

void getPoints(Point *ptr)
{
    cout << "Enter the x-coordinate: ";
    // cin >> (*ptr).x;
    cin >> ptr->x;
    cout << "Enter the y-coordinate: ";
    // cin >> (*ptr).y;
    cin >> ptr->y;
}
void displayCircle(Circle &c)
{
    cout << "Center is: ";
    displayPoint(c.center);
    cout << "Radius is: " << c.radius << endl;
}
Point getPoints()
{
    Point temp;
    cout << "Enter the coordinates: ";
    cin >> temp.x >> temp.y;

    return temp;
}

void inputArray(Point *pts, int size)
{
    for (int i = 0; i < size; i++)
    {
        pts[i] = getPoints();
    }
}
void displayArray(const Point *pts, int size)
{
    for (int i = 0; i < size; i++)
    {

        // cout << "(" << pts[i].x << " " << pts[i].y << ")";
        displayPoint(pts[i]);
    }
}

int main()
{
    Point pt1;
    Point pt2 = {10, 12};

    // Pointer to a structure

    Point *ptr1 = &pt1; // This pointer ptr1 is pointing to Address of pt1

    // Accessing Point values

    /*(*ptr1).x = 7; // Dot Operatore has higher precedence so we have to use prentheses.
    (*ptr1).y = 10;

    // Can also be done by Arrow Operator

    ptr1->x = 6;     // "->" Operator automatically dereference the pointer formally called Structure Pointer Variable
    ptr1->y = 19;*/

    // Inputing by a function containing function

    // getPoints(ptr1);

    // if you don't have a pointer to that structure variable simply you can send its address. i.e.

    // getPoints(&pt1);

    // displayPoint(pt1);

    // Nested Structures

    /* Circle c1;
     c1.center.x = 5;
     c1.center.y = 6;
     c1.radius = 6.4;

     displayCircle(c1);

     Circle c2 = {2, 3, 7.8};

     displayCircle(c2);*/

    const int N = 5;
    Point points[N];

    // Array of Structure Variables- Heap Implementation

    /*int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    Point *pts = new Point[size];

    inputArray(pts, size);
    displayArray(pts, size);

    delete[] pts;
    pts = nullptr;*/

    // TO DO
    //  Dynamicall allocation of circle structure claculate areas etc.

    // Creating new object of Heap

    Circle *cp = nullptr;

    cp = new Circle; // On - Heap

    /*(*cp).center.x = 5;
      (*cp).center.y = 6;
      (*cp).radius = 3.5;*/

    // Can be done by Arrow-Operator

    cp->center.x = 5;
    cp->center.y = 6;
    cp->radius = 3.5;

    delete cp;
    cp = nullptr;

    // When to use . and when to use ->

    // On the left side of . operator there will be    a variable/object.
    // On the left side of -> operator there will be   a pointer.

    twoVals v1;
    v1.num = 10;
    v1.ptr = new int;

    *(v1.ptr) = 55;
    cout << v1.num << " " << v1.ptr << " " << *(v1.ptr) << endl;

    delete v1.ptr;
    v1.ptr = nullptr;

    // --------------------------------------------------------

    twoVals *vp = nullptr;

    vp = new twoVals;

    vp->num = 42;
    vp->ptr = new int;

    *(vp->ptr) = 70;

    cout << vp->num << " " << *(vp->ptr) << endl;

    delete vp->ptr;
    vp->ptr = nullptr;

    delete vp;
    vp = nullptr;

    //-----------------------------------------------------------

    twoVals *arr = new twoVals[N];

    // Each arr[i] is a twoVals object/variable.

    for (int i = 0; i < N; i++)
    {
        arr[i].num = 12;
        arr[i].ptr = new int;
        *(arr[i].ptr) = 50;
    }

    for (int i = 0; i < N; i++)
    {
        cout << arr[i].num << " " << *(arr[i].ptr) << endl;
    }

    for (int i = 0; i < N; i++)
    {
        delete arr[i].ptr;
        arr[i].ptr = nullptr;
    }

    delete[] arr;
    arr = nullptr;

    return 0;
}
