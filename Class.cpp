// File Contain:  Concept of classes and objects
// Getters and Setters
// Creating Array of objects and creating it using memory allocation.

#include <iostream>
#include <string>

using namespace std;

void deallocateMemory(int *&p) // Pointer is coming as a copy we should pass it as a reference so that it can nullify the original pointer.
{                              // Pointer can also be passed by reference.
    delete p;
    p = nullptr;
}

class Point
{
private: // Data of the class must be hidden from the outside world so make it private.(Information Hiding)
    int x;
    int y;

public:
    // Setter Functions   (Modify)    Mutator Functions
    // void setX(int val)
    // {
    //     x = val;
    // }
    void setX(int); // Defination is written outside the class.
    void setY(int);

    void setCoordinates(int, int);

    // Getter Functions (Read)     Accesser Functions
    // Getter shouldn't have right to modify the member variable's value so, we use const keyword.
    // Getters should be written as a CONSTANT MEMBER FUNCTIONS.

    int getX() const;

    int getY() const;

    void displayPoint() const;
};

void Point::setX(int val) // :: ---> is a SCOPE RESOLUTION operator.
{
    x = val;
}
void Point::setY(int val)
{
    y = val;
}
int Point::getX() const
{

    return x;
}
int Point::getY() const
{

    return y;
}
void Point::displayPoint() const
{
    cout << "(" << x << ", " << y << ")\n";
}
void Point::setCoordinates(int v1, int v2)
{
    x = v1;
    y = v2;

    // setX(v1);
    // setY(v2);
}

int main()
{
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

    /*int *ptr = new int;
    *ptr = 40;
    cout << &ptr << " " << *ptr << endl;
    deallocateMemory(ptr);

    if (ptr == nullptr)
    {
        cout << "Ptr is NULL!";
    }
    else
    {
        cout << "Ptr is not NUll!";
    }*/

    // ARRAY of Points

    const int N = 4;
    // Point pts[N];

    // Creating Dynamically Allocated Array of Points
    int n;
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
    pts = nullptr;
    return 0;
}