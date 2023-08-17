#include <iostream>
#include "Point.cpp"

using namespace std;

int main()
{

    Point pt1; // At the time of creating object ot instance they contain junk values.
               // so we implement a function called constructor to set some default values.
               // Default constructor automatically called while creating object.
    Point pt2(3, 4);
    const int N = 3;
    Point pt3[N] = {{2, 3}, {4, 5}}; // Inilization method used for only statically allocated arrays.

    Point pt4(7);

    pt1.displayPoint();

    pt2.displayPoint();

    for (int i = 0; i < N; i++)
    {
        pt3[i].displayPoint();
    }

    pt4.displayPoint();

    const Point origin(0, 0);
    // origin.setX(2);   // ERROR: Non Const function can't be called.
    origin.displayPoint();

    /*Point p1; // p1 is an object/instance of class Point.
    // p1.x = 10;   // ERROR: Private members are inaccessible
    // p1.y = 11;    // ERROR: Private members are inaccessible

    p1.setX(5);
    p1.setY(10);
    cout << "P1 Contains: ";
    cout << p1.getX() << " " << p1.getY() << endl;

    Point p2;

    int tempX, tempY;
    cout << "Enter Coordinates: ";
    cin >> tempX >> tempY;
    p2.setX(tempX);
    p2.setY(tempY);

    cout << "P2 Contains: ";
    cout << p2.getX() << " " << p2.getY();

    // Creating objects on HEAP

    Point *ptr = new Point;
    //(*ptr).setX(50);
    // OR
    ptr->setX(50);
    ptr->setY(60);

    cout << "\nPoints on Heap are: ";
    // cout << ptr->getX() << " " << ptr->getY() << endl;
    ptr->displayPoint();

    delete ptr;
    ptr = nullptr; */

    // ARRAY of Points

    // const int N = 4;
    //  Point pts[N];

    // Creating Dynamically Allocated Array of Points

    /*int n;
    cout << "Enter the Number of points you want to create? : ";
    cin >> n;
    Point *pts = new Point[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cout << "Enter Coordinates of Point no. " << i + 1 << " : ";
        cin >> a >> b;
        // pts[i].setX(a);
        // pts[i].setY(b);

        pts[i].setCoordinates(a, b);
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\n Point " << i + 1 << " is: ";
        pts[i].displayPoint();
    }

    delete[] pts;
    pts = nullptr;*/

    return 0;
}