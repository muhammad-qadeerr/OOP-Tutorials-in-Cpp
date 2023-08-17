#include <iostream>
#include <string>
using namespace std;

// Structute - Defination      creating a structure not allocating any memory, blue print, stensil
struct Student
{
    int rollNo; // 4 bytes
    // char name[41];  // 41 bytes
    string name;
    double cgpa; // 8 bytes
                 // Total memory = 4 + 41 + 8 = 53 Bytes
};

int main()
{
    // Primitive(Built-in DataTypes) --> int, float, char, short, double  .....

    // We can also creat Programmer Defined DataTypes or Abstract DataTypes (ADT)

    /*int rollNo[50];
    //string name;
    char name[50][41];  //Char String of max 40 lenght 1 for null character at the end.
    double cgpa[50];    // For storing data for 50 student we use the concept of PARALLEL ARRAYS in
                        // which all three data i.e. rollno, cgpa, name in placed on same index of array for each student.
                        // But we can not serperatly deal with 1 student data so, we use structure.*/

    /*//Student st1{2, "Ali", 3.4}; ->> Modern initialization.
    Student st1 = {3, "Abc Def", 3.4};
    // Partial Inizialization can also be done!
    Student st2, st3; // Same as declaring a variable
    // Student st2 = st1, st3 = st1;   // WILL WORK Also.

    // st2 = {234, "Ali", 3.45}; -> this will also work in C++ 11 Now.

    // Accesssing Structure members - We use DOT Operator

    // st1.rollNo = 3;
    // st1.name = "Abc Def";
    // st1.cgpa = 3.23;

    cout << st1.name << endl;
    cout << st1.rollNo << endl;
    cout << st1.cgpa << endl;

    cout << "Enter the roll no: ";
    cin >> st2.rollNo;
    cout << "Enter the CGPA: ";
    cin >> st2.cgpa;

    // After taking number input it remain \n in buffer so it will not wait for string input so use cin.ignore().
    // Previous input was taken by insertion operator so use cin.ignore();

    cin.ignore();
    cout << "Enter the name: ";
    // cin >> st2.name;  // Use getline if string include space
    getline(cin, st2.name);

    cout << "***Information from st2***" << endl;
    cout << st2.name << endl;
    cout << st2.rollNo << endl;
    cout << st2.cgpa << endl;

    // st3.cgpa = st2.cgpa;
    // st3.name = st2.name;
    // st3.rollNo = st2.rollNo;

    // Only Assignment can be done i.e copying data (Bitwise copy)

    st3 = st2; // Byte-by-Byte Copy.

    cout << "***Information from st3***" << endl;
    cout << st3.name << endl;
    cout << st3.rollNo << endl;
    cout << st3.cgpa << endl;

    // cout << st3; // WILL NOT WORK!! - Must be proceed member by member.
    // cin >> st2;
    // Also no relational or comparison operator can be used
    // WILL NOT WORK
    // if(st1<st2)
    // {
    //     cout << "St1 is Smaller";

    // }
    // else
    // {
    //     cout << "St2 is smaller";
    // }

    // Input, output, and comparision operation WILL NOT WORK aggregately (ikhta)
    // These must be done member-by-member.

    // if (st2.name == st3.name && st2.rollNo == st3.rollNo && st2.cgpa == st3.cgpa)
    // {
    //     cout << "Both Students are same \n";
    // }
    // else
    // {
    //     cout << "Both Students are Different\n";
    // }*/

    // ARRAY OF STRUCTURE
    // Now, for example you want to manage the data of 50 student you should use Array of Structure.

    const int N = 50;

    Student st[N]; // Continuous portion of memory (bytes) multiplied with array size i.e. 53*50

    // Initialization syntax

    /*Student Student[3] = {
                            {1,"Ali", 3.4},
                            {2, "Haider", 3.5},
                            {3, "Asfand", 3.6}
                        };*/

    // Inputting in array of structure

    for (int i = 0; i < N; i++)
    {
        // Each st[i]  --> is a Student
        cout << "Enter the roll number of Student " << i + 1 << " : ";
        cin >> st[i].rollNo;
        cout << "Enter the CGPA of Student " << i + 1 << " : ";
        cin >> st[i].cgpa;
        cin.ignore();
        cout << "Enter the name of Student " << i + 1 << " : ";
        // cin >> st[i].name;
        getline(cin, st[i].name);
    }

    // Outputting Array of Structure

    for (int i = 0; i < N; i++)
    {
        cout << "\nRoll number of Student " << i + 1 << " : ";
        cout << st[i].rollNo;
        cout << "\nCGPA of Student " << i + 1 << " : ";
        cout << st[i].cgpa;

        cout << "\nName of Student " << i + 1 << " : ";
        cout << st[i].name;
    }

    // Strings functions at Page number 599 or Gaddis Book.
    return 0;
}