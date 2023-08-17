#include <iostream>
using namespace std;
// Dynamic Memory Allocation on Array.

int main()
{
    /* int num;
     // Through heap now it is possible to make an array of variable size
     // i.e. we normally use dynamic memory concept with array.

     cout << "Enter the no. of elements you want to store in an array: ";
     cin >> num;
     int arr[4];
     int *ptr = nullptr;

     int *p2 = new int[num]; // Array Memory-Allocation
     cout << "Enter the value in an array: ";
     for (int i = 0; i < num; i++)
     {
         cin >> p2[i];
     }
     cout << "Content of an array are: ";
     for (int i = 0; i < num; i++)
     {

         cout << p2[i] << " ";
     }
     cout << endl;
     // The array allocated on heap will not be destroyed after processing which creat the issue of memory leak
     // so we have to delete it by writting the following code.

     delete[] p2; // This De-allocate the array on heap, whose base address in contained in pointer.
     // now "p2" is still pointing the array i.e. it still contain the base address of de-allocated array
     // it can create the issue i.e. DANGLING POINTER,  can be solved as,

     p2 = nullptr;*/

    // MEMORY LEAK and DANGLING POINTERS  (Details)

    /*int *p1 = new int;
    int *p2 = new int;

    *p1 = 11;
    *p2 = 35;

    cout << *p1 << " " << *p2 << endl;

    //delete p1;
    //p1 = nullptr;   // now you can use p1 without creating any issue.

    int *p3 = p1;

    p1 = p2;    // Both pointers pointing to same memory address. p1 at heap created a memory leak issue.

    cout << *p1 << " " << *p2 << endl;

    p1 = p3;   //become same memory location,

    // p1 be deleted only once
    delete p1;
    p1 = nullptr;
    p3 = nullptr;
    //also

    delete p2;
    p2 = nullptr;*/

    // 2D ARRAYS DYNAMICALLY ALLOCATION

    int arr[3][5];
    int r, c;
    // cin >> r >> c;
    // int arr1 [r][c];
    r = 5, c = 4;

    // int *arr = new int[r];  // 2d array allocation syntax

    // arr[i]  --> int

    // int *arr =new int *[r];  // Type miss-match error

    /*int a;
    int *p = &a;
    int **p1 = &p;  // pointer to pointer in this case  p2 ---> p  ---> a

    a = 5;
    *p = 5;
    **p1 = 5;   // All these statements will work same and will store 5 in "a"*/

    int **marks = new int *[r]; // 2D array allocated with double pointers
    // marks[i]  --> int*
    // arr[i] == *(arr + i)  Equivalent pointer expression for 1D array

    // ALLOCTION

    for (int i = 0; i < r; i++)
    {
        marks[i] = new int[c];
    }

    // Inputting in dynamically allocated 2D array

    marks[3][2] = 50;         // it access element of 4th row and 3rd coloumn
    *(*(marks + 3) + 2) = 74; // Both expressions are equivalent

    // arr[i][j] = *(*(arr + i) + j);  Equivalent pointer expression for 2D array

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            // cin >> marks[i][j];
            cin >> *(*(marks + i) + j);
        }
    }

    // DE_ALLOCATION

    // DeAllocation of inside array contained in rowa
    for (int i = 0; i < r; i++)
    {
        // marks[i] = new int[c];
        delete[] marks[i];
        marks[i] = nullptr;
    }

    // DeAllocation of main Array outside
    delete[] marks;
    marks = nullptr;

    /* File Handling Revision

    1. No. of elements known (constant)
    2. No. of elements stored in a file.
    3. Elements are terminated by a sentinal value
    4. Reading data till end of the file. */

    return 0;
}