// File Containe:  Test Class
// Array of Object on Heap
// Destructor. (Imp to write in such classes whose member variables are pointers and memory created on heap).
// Orders of Destructor and COnstructor.
// Dangling Pointer, Heap Allocation.
// Cosnstructor Delegation - From Gaddis Book.
// Overloaded Assignment Operator from lecture 13.
// Overloaded Assignment Operator for pointer data members.
// Differences between Asssignment operator implementation and CC implementation.

#include <iostream>
using namespace std;

class Test
{
private:
    int val;
    int *p;

public:
    Test() : val(0) // This is called Member Initialization/Initializer List. (Pointers can't be initialized by this list)
    {
        // val = 0;
        p = new int;
        *p = 0;
        cout << "Created through Default constructor: " << val << " " << *p << endl;
    }

    Test(int v1, int v2) : val(v1) // This is done only in case of constructors and one other function will be discussed later.
    {
        // val = v;
        p = new int;
        *p = v2;
        cout << "Created through Parameter constructor: " << val << " " << *p << endl;
    }
    void setVal(int temp)
    {
        val = temp;
    }
    void display() const
    {
        cout << "Value: " << val << endl;
        cout << "Pointer: " << *p << endl;
    }
    // Destructor
    // Telda sign and name same as class.
    // Each Class has only one destructor.
    // Destructor are called in reverse order.

    ~Test()
    {
        cout << "Destructor Called!!!  " << val << " " << *p << endl;

        // De-Allocation with the check whether dynamic memory was created or not.
        if (p != nullptr)
        {
            delete p;
            p = nullptr;
        }
    }
    // Overloaded assignment operator for pointer data members.

    const Test &operator=(const Test &rhs)
    {

        cout << "Test Assignment Operator Called!!" << endl;
        // Difference No.1
        // Check for self assignment
        if (this == &rhs) // (this) is address of current object and &rhs if rhs address we compare them to check the equality.
        {
            cout << "Self assignment id being done!!" << endl;
            return *this;
        }
        else
        {
            val = rhs.val;
            // Difference No.2
            // De-Allocating previously allocated memory (if any) and rellocate memory
            if (p != nullptr)
            {
                delete p;
                p = nullptr;
            }

            // Allocating new memory

            p = new int;
            *p = *(rhs.p);
            // Difference No.3 ReturnType.
            // To use cascaded assignment
            return *this;
        }
    }
};

int main()
{
    /*  Objects when only val was a private data member

    const int N = 3;
    // Test t1;
    // Test t2(5);
    // Test t3[N] = {{1}, {2}, {3}};

    // Creating Objects on Heap

    Test *tp = nullptr; // No Object Created yet.
    // tp = new Test;
    //tp = new Test(5);
    // tp = new Test[N]; // Array Created on Heap can't be initialized.

    delete tp; // Destructor is'nt called during memory leak. this statement make the destructor to call.
    tp = nullptr;*/

    // --------------------------------------------------------------------------------------------------

    // Objects in which heap implementations is done in constructor etc... and deallocation must be done in Destructor.

    // Test t1;
    // Test t2(4, 6);

    // Test *t = new Test;
    // t = new Test(5, 7);
    // // t = new Test[5];
    // // delete[] t;
    // delete t;
    // t = nullptr;

    // // Array of Objects - Heap Implementation

    // Test *t2 = new Test[5];

    // for (int i = 0; i < 5; i++)
    // {
    //     t2[i].setVal(i * 5);
    // }

    // for (int i = 0; i < 5; i++)
    // {
    //     t2[i].display();
    // }
    // delete[] t2;
    // t2 = nullptr;

    //------------------OVERLOADED ASSIGNMENT OPERATOR------------------------------------------------------

    Test t1(10, 20);
    Test t2;

    t2 = t1;

    // Self- Assignment

    t1 = t1;
    t1.display();
    return 0;
}