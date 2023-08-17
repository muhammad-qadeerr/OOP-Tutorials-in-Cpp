#ifndef TEST_H
#define TEST_H

class Test
{
private:
    int val;
    int *p;

public:
    Test();

    Test(int, int);

    void setVal(int);

    void display() const;
    ~Test();

    // Overloaded assignment operator for pointer data members.

    const Test &operator=(const Test &);
};
#endif