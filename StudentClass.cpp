// File Contain: Char pointer issue and information hiding principle using student class
// Const Keyword.

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int N = 30;
class Student
{
private:
    char name[N + 1];
    int rollNum;
    string adress;

public:
    /*int * getRollNum()    Never do this because information can be modified later when retrurning a pointer
    {                       It is totally against the principles of information hiding.
        return &rollNum;

    }*/
    string getAdress() const
    {
        return adress;
    }
    Student() // Default Constructor
    {
        cout << "Default Constructor Called!!!" << endl;
        strcpy(name, "");
    }

    Student(char *n) // Parameterized Constructor
    {
        cout << "Parameterized Constructor Called!!!" << endl;
        strcpy(name, n); // Assignment operator can't work with char strings.
    }

    void setName(char *n)
    {
        strcpy(name, n);
    }

    const char *getName() const // Getter don't have right to modify.   (Pointer to a char pointer must be written.)
                                // You are returnedd a pointer to a private data member so it can modify it later it should be constant char pointer.
    {
        return name;
    }
    void displayStudent() const
    {
        cout << "Name is: " << name << endl;
    }
};
int main()
{
    // Student st1("Ali");   // This type of char array initialization will give error bcz it take it as const char array.

    char temp[N + 1];
    strcpy(temp, "Ali");

    Student st1(temp);

    st1.displayStudent();

    // char *nm = st1.getName(); // Don't follow the informtion hiding rules for private data member rule/
    //  Rule says that it should only be accessed by class member function but it is beign accessed here by some char * nm Variable.

    // cout << "In main: " << nm << endl;

    // strcpy(nm, "Ahmad"); // More dangerour bcz private data member should not be modified.

    st1.displayStudent();

    return 0;
}