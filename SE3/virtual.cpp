#include <iostream>
#include <conio.h>
using namespace std;

class Shape
{
public:
    double x, y;
    virtual float computeArea() = 0;
};

class Triangle : public Shape
{
public:
    float computeArea()
    {
        return 0.5 * x * y;
    }
};

class Rectangle : public Shape
{

public:
    float computeArea()
    {
        return x * y;
    }
};

int main()
{
    Shape *s;
    Triangle t;
    Rectangle r;

    t.x = 10;
    t.y = 10;

    r.x = 10;
    r.y = 10;

    s = &t;
    cout << "Area of Triangle: " << s->computeArea();
    s = &r;
    cout << "\nArea of Rectangle: " << s->computeArea();

    getch();
    return 0;
}
