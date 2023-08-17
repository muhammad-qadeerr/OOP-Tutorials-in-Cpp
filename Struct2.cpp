#include <iostream>
using namespace std;

struct Student
{
    // These are the member variables
    int rollNo;
    string name;
    double cgpa;
};
struct Point // Point takes 8 byte in the memory.
{
    int x;
    int y;
};

// Same name function can not be declared by value and by reference at the same time.
/*void displayPoint(Point p) // Pass by value - means Copy will b e created when the function is called.
                           // Parameters are Local Variables of the function.
{
    // << "The Address of P in display function is: " << &p << endl;
    cout << "The Point contains: (" << p.x << "," << p.y << ")" << endl;
    // p.x = 0;
    // p.y = 0;   // Value will retain as it was previously it won't change during function call.
}*/
// We should add const refernce so that it can't modify the values of parameters during call.
void displayPoint(const Point &p) // Pass by reference - no COPY is created.
                                  // Parameters are Local Variables of the function.
{
    // cout << "The Address of P in display function is: " << &p << endl;
    cout << "The Point contains: (" << p.x << "," << p.y << ")" << endl;
    // p.x = 0;
    // p.y = 0; // Value will modified after function call as it is being called by reference.
}
void getPoints(Point &p)
{
    cout << "Enter the x-coordinate: ";
    cin >> p.x;
    cout << "Enter the y-coordinate: ";
    cin >> p.y;
}

Point getPoints()
{
    Point temp;
    cout << "Enter the coordinates: ";
    cin >> temp.x >> temp.y;

    return temp;
}

void inputArray(Point pts[], int size)
{
    for (int i = 0; i < size; i++)
    {
        // getPoints(points[i]);
        //  OR
        pts[i] = getPoints();
    }
}
void displayArray(Point pts[], int size)
{
    for (int i = 0; i < size; i++)
    {

        // cout << "(" << pts[i].x << " " << pts[i].y << ")";
        displayPoint(pts[i]);
    }
}

int main()
{
    /*// Can be initialization in both ways
    Student st1 = {1, "Adc Def", 3.4};
    Student st1 {1, "Adc Def", 3.4};*/

    Point pt1;
    Point pt2 = {10, 12};

    /*cout << "\n IN MIAN\n";
    cout << "The Address of Pt1 is: " << &pt1 << endl;
    cout << "The Address of Pt2 is: " << &pt2 << endl;*/
    // Mathod 1
    // getPoints(pt1);

    // Method 2
    // pt1 = getPoints();
    /*cout << "Enter the x-coordinate: ";
    cin >> pt1.x;
    cout << "Enter the y-coordinate: ";
    cin >> pt1.y;*/

    /*displayPoint(pt1);
    cout << "\n\n";
    displayPoint(pt2);

    cout << "\n BACK IN MIAN\n";
    cout << "The Point contains: (" << pt1.x << "," << pt1.y << ")" << endl;
    cout << "The Point contains: (" << pt2.x << "," << pt2.y << ")" << endl;*/

    const int N = 5;
    Point points[5];

    // Inputting in an array using function

    /* for (int i = 0; i < 5; i++)
     {
         // getPoints(points[i]);
         //  OR
         points[i] = getPoints();
     }*/

    inputArray(points, N);

    // Display that array

    displayArray(points, N);

    /*for (int i = 0; i < 5; i++)
    {
        displayPoint(points[i]);
    }*/

    return 0;
}

// Procedural Programming
    // It refers to use functions to eleborate the programm.