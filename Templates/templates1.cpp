/*
    - Templates are very powerful tool in c++
    - Templates are foundation of generic programming, which involves writing code in a way that is
        independent of any datatype.
    - Templates are blueprints for creating a generic class or functions.
    - Two types:
            - Function Templates
            - Class Templates
*/

#include <iostream>
using namespace std;

// Class Template

template <typename T, typename U>

class Weight
{
private:
    T kg;
    U grams;

public:
    void setData(T x, U y)
    {
        kg = x;
        grams = y;
    }
    T getKgData() const
    {
        return kg;
    }
    U getGramsData() const
    {
        return grams;
    }
};

// Function Template
template <typename T>
T add(T x, T y)
{
    return (x + y);
}

// GCD Code

template <typename T>

int main()
{
    Weight<int, double> w1;
    w1.setData(8, 0.56);
    cout << "KG Data is: " << w1.getKgData() << endl;
    cout << "Grams Data is: " << w1.getGramsData() << endl;

    // Weight<double> w2;
    // w2.setData(8.4567);
    // cout << "Data is: " << w2.getData() << endl;

    // Function Templates
    cout << "------Sum using add function Template-----" << endl;
    cout << add<int>(3, 4) << endl;
    cout << add<double>(4.534, 8.906) << endl;
    //  cout << add<char>('a', 'b');

    return 0;
}