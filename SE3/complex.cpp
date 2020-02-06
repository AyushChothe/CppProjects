#include <iostream>
#include <conio.h>

using namespace std;

class Complex
{
    int r, i;

public:
    Complex() {}
    Complex(int x, int y)
    {
        r = x;
        i = y;
    }

    friend Complex operator+(Complex, Complex);
    friend Complex operator-(Complex, Complex);

    Complex operator*(Complex c2)
    {
        Complex c3;

        c3.r = (r * c2.r) - (i * c2.i);
        c3.i = (r * c2.i) + (c2.r * i);

        return c3;
    }

    Complex operator/(Complex c2)
    {
        Complex c3;

        c3.r = ((r * c2.r) + (i * c2.i)) / ((c2.r * c2.r) + (c2.i * c2.i));
        c3.i = ((i * c2.r) - (r * c2.i)) / ((c2.r * c2.r) + (c2.i * c2.i));

        return c3;
    }

    void getData()
    {
        cout << "Enter Real Part: ";
        cin >> r;
        cout << "Enter Imaginary Part: ";
        cin >> i;
    }

    void display()
    {
        cout << r << " + " << i << "i\n";
    }
};

Complex operator+(Complex c1, Complex c2)
{
    Complex c3;
    c3.r = c1.r + c2.r;
    c3.i = c1.i + c2.i;

    return c3;
}

Complex operator-(Complex c1, Complex c2)
{
    Complex c3;
    c3.r = c1.r - c2.r;
    c3.i = c1.i - c2.i;

    return c3;
}

int main()
{
    Complex c1(10, 10), c2(5, 5), c3;
    int ch;

    cout << "Enter Complex 1:\n";
    c1.getData();
    cout << "Enter Complex 2:\n";
    c2.getData();

    while (1 > 0)
    {
        cout << "Choose Operation:\n1.Add\n2.Sub\n3.Multiply\n4.Divide\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            c3 = c1 + c2;
            c3.display();
            break;
        case 2:
            c3 = c1 - c2;
            c3.display();
            break;
        case 3:
            c3 = c1 * c2;
            c3.display();
            break;
        case 4:
            c3 = c1 / c2;
            c3.display();
            break;

        default:
            cout << "Invalid Choice!";
            break;
        }
    }
    return 0;
}