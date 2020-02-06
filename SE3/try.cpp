#include <iostream>
#include <conio.h>
using namespace std;

class Division
{
    double a, b;

public:
    void getData()
    {
        cout << "Enter a & b:\n";
        cin >> a >> b;
    }

    void divide()
    {
        try
        {
            if (b == 0)
            {
                throw 1;
            }
            cout << "\nDivision is: " << a / b;
        }
        catch (int ex)
        {
            cout << "\nDivide by Zero Exception!\n";
            cout << "Hello";
        }
    }
};

int main()
{

    Division d;

    d.getData();
    d.divide();

    getch();
    return 0;
}