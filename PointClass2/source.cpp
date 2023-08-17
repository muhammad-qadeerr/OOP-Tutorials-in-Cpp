/* FILE CONTAIN:  Lecture 12/13/14/15  (lec15 3-11-2022)
    - Operator Overloading.   (Increase readibility of code.)
    - Friend Function in Lec 13.
        - If we want to access private data members of the class than we make that non member function as friend function.
        - Use this concept very sparingly , only in case of non-member function
        - Because it violate the concept of "Information Hiding".
    - Another usage of assignment operator is discussed in the test class.
    - Differences between Asssignment operator implementation and CC implementation. (in the test class)

Lecture 14.  OPERATOR OVERLOADING CONTINUE....
         - Operator whose left operend is not the object of same class must be implemented as NON_ MEMBER Function.
         i.e cout<< p1;   (cout is not a class object like other operators like +,-, += etc etc)
         - OVERLOADING INSERTION and EXTRACTION OPERATORS

    - Big Three- if you implemented 1 function you just implement these three functions.
        1. Destructor
        2. Copy constructor
        3. Assignment operator

Lecture 15. OPERATOR OVERLOADING CONTINUE.
        - Overloading Index operator
        - Overloading Function Call Operator.
        - Conversion from User-Defined DataType to Pre-defined DataType. (Conversion Operator Overloading) int val = p1;
        - Conversion from a Pre-defined DataType to a User-Defined DataType   p1 = val;  -> These are bacsically Constructors.
        - Conversion Constructoor from int to a point Conversion.


*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Point.cpp"

Point operator+(int val, const Point &p) // NON-MEMBER FUNCTION
{
    // We overload this operator as non member bcz left operend was not class object.
    // 1.
    // Point sum(val + p.getX(), val + p.getY());

    // 2.
    //  sum.setX(val + p.getX());
    //  sum.setY(val + p.getY());
    // 3.
    //  sum.x = val + p.x; // ERROR: x,y are inaccessible
    //  sum.x = val + p.y;

    // ===> Now it will work bcz function is now friend function of the class.
    Point sum;
    sum.x = val + p.x; // NO ERROR: x,y are accessible now.
    sum.x = val + p.y;
    return sum;
}

// -------- Lec 14 (Non- Member operator overloading) ---------------
ostream &operator<<(ostream &o, const Point &pt)
{
    o << "(" << pt.x << " , " << pt.y << ")" << endl; // ERROR: x,y inaccessible so we make it friend in point.h

    return o;
}

istream &operator>>(istream &in, Point &pt)
{
    in >> pt.x;
    in.ignore();
    in >> pt.y;

    return in;
}

int main()
{
    Point p1(2, 3);
    Point p2(2, 6);
    Point p3(6, 7);
    Point p4;
    // -------------------------OVERLOADING ARTHMETIC OPERATORS --------------------------------
    // p4 = p1.add(p2);
    // p4 = p4.add(p3);
    // OR
    // p4 = p1.add(p2).add(p3);
    // BUT
    // p4 = p1 + p2;  // This won't work but can be done by OPERATOR OVERLOADING.

    // p4 = p1 + p2;
    // p4 = p1 + p2 + p3;

    // p4 += p1;

    // Cascaded use of += operator

    // p3 += p2 += p1; // This won't work because function is not returing anything. (we have to change the data type)
    // p4 += p3 += p2 += p1; // Now it will work

    // Adding an int to a point

    // p4 = p1 + 10;
    //  p4 = 10 + p1;   // This won't work.

    // Subtracting two points.

    // p4.displayPoint();

    // ----------------------------------------OVERLOADING RELATIONAL OPERATORS (returntype always bool) --------------------------------

    // if (p1 == p2)
    // {
    //     cout << "Both points are same." << endl;
    // }
    // else
    // {
    //     cout << "Both points are not same." << endl;
    // }

    // if (p1 != p2)
    // {
    //     cout << "Both points are NOT same." << endl;
    // }
    // else
    // {
    //     cout << "Both points are same." << endl;
    // }
    // p3.displayPoint();
    // // p2 = ++p3;
    // p4 = p3++;
    // p3.displayPoint();
    // p4.displayPoint();

    //--------------------------------------------LECTURE 13---------------------------------------------------------
    // Overloading Unary - Operator.

    // int a = 5;
    // int b = -a;
    // cout << a << " " << b << endl;

    // p1 = -p2;

    // p2.displayPoint();
    // p1.displayPoint();

    // p2 = 10 + p1; // ERROR: NO Such Operator.
    //  it can be implemented using FRIEND function
    // We have to implement a global function in source.cpp for this case.

    // p4 = 10 + p1;
    // p1.displayPoint();
    // p4.displayPoint();

    // p1 = p2;
    // p1.displayPoint();
    // p2.displayPoint();

    // p3 = p2 = p1; // Cascaded assignment

    // p1.displayPoint();
    // p2.displayPoint();
    // p3.displayPoint();

    //--------------------------------LECTURE 14 ------------------------------------------------------

    // STREAM INSERTION OPERATOR OVERLOADING --------------------------------
    // cout << p1;
    // Operator << implemented as member function will work as
    // p1 << cout;

    // cout << p2 << p3;

    // STREAM EXTRACTION OPERATOR OVERLOADING --------------------------------
    // cout << "Enter a Point: ";
    // cin >> p3;
    // cout << "You Entered: " << p3;

    // READING AND WRITTING IN FILE USING OVERLOADED OPERATORS.

    // ofstream fout;
    // fout.open("output.txt");

    // if (!fout)
    // {
    //     cout << "ERROR Opeening file!!" << endl;
    // }
    // else
    // {
    //     fout << p2 << p3;
    //     fout.close();
    // }

    // OVERLOADING INDEX [] Operator

    // cout << p1['x'] << " " << p1['y'] << " " << endl;

    // --------------------------------------Lecture 15 (3-11- 2020)-----------------------------------

    // We are going to implement index operator so that it can modify the point.
    // p1['x'] = 11;
    // cout << p1;

    // Function Call Operator = this function adds in current object and modify one on Left hand Side.

    // p2 = p1(4, 5);
    // cout << p2;

    // Conversion Operator.

    int val, val1;
    val = p1 + p2;
    val1 = p1;

    cout << "Values are: " << val << " " << val1 << endl;

    string s = p1;

    cout << "The point string is: " << s << endl;

    // TO DO:
    // char *cs = p1;

    // Using Conversion Constructors

    // A (Explicit way of conversion)
    // Point p5(12);

    //  B  (Will no work whem cov. constructor is explixit)
    // Point p6 = 25;

    //  C - Asignment/Default/ and conversion Operator will be called.
    // (Will no work whem cov. constructor is explixit)

    // Point p6;
    // p6 = 35;

    // D  (Explicit way of conversion)
    // We make this constructor explicit so that it can only be run by explicit keyword .

    Point p7;
    p7 = static_cast<Point>(25);

    // p5.displayPoint();
    // p6.displayPoint();
    p7.displayPoint();

    // E
    // p7 = p6 + 11;   // this will work only woth point to point addition operator so we'll use aa conversion od 11 to point so that it may run.

    // FeetInches Class from GADDIS Book [page 844-858] and [page 864,865].
    // intArray Class [page 458 to onwards.]

    return 0;
}