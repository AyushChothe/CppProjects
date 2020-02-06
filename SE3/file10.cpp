#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
using namespace std;

class Person
{
    string name;
    int age;

public:
    void setData()
    {
        cout << "Name & Age:" << endl;
        cin >> name >> age;
    }

    void getData()
    {
        cout << "Name: " << name << "\nAge: "
             << age << endl;
    }
};

fstream file;
Person p;

int main()
{
    int ch;

    while (1 > 0)
    {
        cout << "Enter Choice:\n1. Insert Record\n2. Display Record\n3. Edit Record\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            file.open("data.dat", ios::out);

            p.setData();

            file.write((char *)&p, sizeof(p));

            file.close();
            break;
        case 2:
            file.open("data.dat", ios::in);

            file.read((char *)&p, sizeof(p));
            while (!file.eof())
            {
                p.getData();
                file.read((char *)&p, sizeof(p));
            }

            file.close();
            break;

        default:
            break;
        }
    }
    return 0;
}