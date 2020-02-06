#include <iostream>
#include <conio.h>
using namespace std;

template <class T, int n = 2>
class Matrix
{
    T a[n][n];

public:
    void setM()
    {
        cout << "Enter Matrix(" << n << "):\n";
        for (int ij = 0; ij < n * n; ij++)
        {
            cin >> a[ij / n][ij % n];
        }
    }

    Matrix operator+(Matrix b)
    {
        Matrix c;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                c.a[i][j] = a[i][j] + b.a[i][j];
            }
        }
        return c;
    }

    Matrix operator-(Matrix b)
    {
        Matrix c;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                c.a[i][j] = a[i][j] - b.a[i][j];
            }
        }
        return c;
    }

    Matrix operator*(Matrix b)
    {
        Matrix c;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                c.a[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                    c.a[i][j] += a[i][k] * b.a[k][j];
                }
            }
        }
        return c;
    }

    void operator-()
    {
        cout << "\nMatrix Transpose:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[j][i] << " ";
            }
            cout << endl;
        }
    }

    void display()
    {
        cout << "\nMatrix:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix<float, 3> a, b, c;

    a.setM();
    b.setM();

    c = a + b;
    c.display();

    c = a - b;
    c.display();

    c = a * b;
    c.display();

    -c;

    getch();
    return 0;
}
