#include <iostream>
#include "Sample.h"
using namespace std;

int Sample ::s = 0; // Static Variable has "0" as a default value
Sample::Sample()
{
    cout << "Default Constructor  Called!! " << this << endl;
    num = 0;
    s = s + 10;
}
Sample::Sample(int n)
{
    cout << "Overloaded Constructor Called!! " << this << endl;
    num = n;
    s = s + 1;
}
Sample::~Sample()
{
    cout << "Destructor Called!! " << this << endl;
}
Sample::Sample(const Sample &orig)
{
    cout << "Copy Constructor Called!! " << this << endl;
    num = orig.num;
}
void Sample::display()
{
    cout << "In the display function: " << num << " " << s << endl;
}
int Sample::getS()
{
    return s;
}
