#include <iostream>
#include <conio.h>
using namespace std;

class Complex
{
public:
    int r, i;
    Complex()
    {
        r = 0;
        i = 0;
    }
    Complex(int x, int y)
    {
        r = x;
        i = y;
    }

    Complex operator*(Complex c2)
    {
        Complex c3;
        c3.r = (r * c2.r) - (i * c2.i);
        c3.i = (r * c2.i) + (i * c2.r);
        return c3;
    }
    Complex operator/(Complex c2)
    {
        Complex c3;
        c3.r = (r * c2.r) + (i * c2.i) / ((c2.r * c2.r) + (c2.i * c2.i));
        c3.i = (i * c2.r) - (r * c2.i) / ((c2.r * c2.r) + (c2.i * c2.i));
        return c3;
    }

    void display()
    {
        cout << r << "+ i" << i << endl;
    }
};

int main(int argc, char const *argv[])
{

    Complex c1(10, 10), c2(5, 5), c3;

    c3 = c1 * c2;
    c3.display();

    c3 = c1 / c2;
    c3.display();

    getch();
    return 0;
}
