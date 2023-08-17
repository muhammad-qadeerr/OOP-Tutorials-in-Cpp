// File Contains:  Uses of Const keyword
// 1. Named Const   (const int N = 5;)
// 2. Const Function Parameters [void displayPoint(const Point&);]
// 3. Const with pointers  (const int*p;)
// 4. Const return type (const char saleItem :: getItem();)
// 5. Const Member Function (void display() const;)
// 6. Const Member Variables.
// 7. Const Objects.   (Only const member function can be called with the help of const objects.)

#include <iostream>
using namespace std;

class Test
{
private:
    int val;

    // Constant member Variables.  --> only be initialized in the member inilialization list of constructor.

    const int num;

public:
    Test() : val(0), num(99) // const member variables must be initialized in all the constructors.
    {
        // val = 0;

        cout << "Created through Default constructor: " << val << " " << num << endl;
    }

    Test(int v) : val(v), num(v)
    {
        // val = v;

        cout << "Created through Parameter constructor: " << val << " " << num << endl;
    }
    void setVal(int temp)
    {
        val = temp;
    }
    void display() const
    {
        cout << "Value: " << val << endl;
        cout << "Const member Variable: " << num << endl;
    }

    ~Test()
    {
        cout << "Destructor Called!!!  " << val << endl;
    }
};

int main()
{

    // Test t1;
    // Test t2(11);
    //  Const Objects
    const Test t3(60);
    // t3.display();  // diplay() is not a const function at the moment so it can't be called.
    t3.display();

    return 0;
}
