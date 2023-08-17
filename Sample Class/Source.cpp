/* FILE CONTAINS: Lecture 11
 - Copy Consturctor
 - Calling of constructor and destructors.
 - Usage of Static Keyword
    1- Static local variables
    2- Static member variables
    3- Static member functions
    4- Static Objects
 */

#include <iostream>
#include "Sample.cpp"

using namespace std;

Sample sampleTesting()
{
    // for Scenarion A and B.
    // Sample s(15); // Overloaded consgtuctor will be called.
    // return s;

    // for Scenarion C
    return Sample(); // This will call the default constructor.
    return Sample(15);
}

void hello()
{
    // int a = 0;   // without static it will display only 0 five times in the loop.
    static int a = 0; // with static it will display 1,2,3,4,5, as it retains it's value for every function call.
    cout << a << endl;
    a++;
}

void testing()
{
    static Sample temp; // Thsis object will be created and destroyed only once.
}

int main()
{
    // Static Keyword.
    // Static local variables.
    // for (int i = 0; i < 5; i++)
    // {
    //     hello();
    // }

    // Sample s1;
    // Sample s2(18);
    // s1.display();
    // s2.display();
    // cout << "Size of object: " << sizeof(Sample) << endl; // Size 4 will be displayed as static variable will not be the part of object.
    // cout << s1.getS() << endl;
    // cout << s2.getS() << endl;

    // // Static Member Function
    // // cout << getS();    // ERROR: Can't call this function directly in main but solution is making it static.
    // cout << Sample::getS(); // Static member function can be called this way.

    // Static Objects.

    // int a = 11;
    // if (a > 10)
    // {

    //     static Sample s4;
    //     // This will cause the scope of this object till end of the main i.e constructor will be called at end of the main
    //     // whatever block in it is.
    // }
    // else
    // {
    // }
    for (int i = 0; i < 5; i++)
    {
        testing();
    }

    //---------------------------------------------------------------------------------------------------------------------------------------

    // Scenario A:
    // Sample s1;
    // s1 = sampleTesting();      // Copy Constructor will be called.  (Assignment 1 extra object will be created.)
    // s1.display();

    // Scenario B,C:
    // Sample s1 = sampleTesting(); // Copy Constructor will be called.  (initliaization.)
    // s1.display();

    // Above concept is called as Return Value Optimizarion (RVO) "or"  Copy Elision.

    // int a = 11;
    // if (a > 10)
    // {
    //     Sample s1;
    // }
    // else
    // {
    // }

    cout << "Back in main function" << endl;
    return 0;
}