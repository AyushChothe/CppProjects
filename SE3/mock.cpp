#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class Shape
{
protected:
    double x, y;

public:
    virtual double compute_area() = 0;
};

class Rectangle : public Shape
{
public:
    double compute_area()
    {
        return (x * y);
    }

    void getData()
    {
        cout << "Enter Lenght & Breadth:\n";
        cin >> x;
        cin >> y;
    }
};

class Triangle : public Shape
{
public:
    double compute_area()
    {
        return (0.5 * x * y);
    }

    void getData()
    {
        cout << "Enter Base & Height:\n";
        cin >> x;
        cin >> y;
    }
};

int main()
{

    Shape *s;
    Rectangle r;
    Triangle t;
    int ch;
    cout << "Name: Ayush Chothe\nRoll No: 84\nMock Test: 1\n";
    while (1 > 0)
    {
        cout << "********************\n1. Area of Rectangle\n2. Area of Triangle\n3. Exit\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            r.getData();
            s = &r;
            cout << "Area of Rectangle: " << s->compute_area() << endl;
            break;
        case 2:
            t.getData();
            s = &t;
            cout << "Area of Triangle: " << s->compute_area() << endl;
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Invalid Choice!\n";
            break;
        }
    }
    getch();
    return 0;
}