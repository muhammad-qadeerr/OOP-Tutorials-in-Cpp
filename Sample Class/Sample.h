#ifndef SAMPPLE_H
#define SAMPLE_H
class Sample
{
private:
    int num;
    static int s; // Declaration, it will be intialized and defined with scope resolution operator.
                  // Static variables are not the part of object. they are created on another memory location.

public:
    Sample();
    Sample(int);
    ~Sample();
    Sample(const Sample &);
    void display();
    static int getS();
};

#endif
