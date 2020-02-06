#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

class Personal
{
protected:
    string name, city, email;
    int age, mobile;

public:
    void getPerData()
    {
        cout << "Enter Name, Age, City, Mobile & E-mail:\n";
        cin >> name >> age >> city >> mobile >> email;
    }
};

class Acadamic
{
protected:
    int ssc, diploma;

public:
    void getAcaData()
    {
        cout << "Enter SSC Marks & Diploma Marks:\n";
        cin >> ssc >> diploma;
    }
};

class Professional
{
protected:
    string placedIn;
    int year;

public:
    void getProData()
    {
        cout << "Enter Company & Year:\n";
        cin >> placedIn >> year;
    }
};

class Employee : public Personal, public Acadamic, public Professional
{

public:
    void getData()
    {
        getPerData();
        getProData();
        getAcaData();
    }
    void display()
    {
        cout << "Name: " << name << "\nAge: " << age << "\nCity: " << city << "\nMobile: " << mobile << "\nEmail: " << email << "\nS.S.C Marks: " << ssc << "\nDiploma Marks: " << diploma << "\nPlaced In: " << placedIn << " " << year << endl;
    }
    string getName()
    {
        return name;
    }
};

int main()
{
    Employee e[10];
    int i, n, fl, ch;
    string name;
    cout << "Employee Record:\n";
    cout << "Enter Number of Entries: ";
    cin >> n;

    while (1 > 0)
    {
        cout << "\n--------------------\nSelect Operation:\n1.Add Entry\n2.Display\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            for (i = 0; i < n; i++)
            {
                cout << "\nEmployee " << i + 1 << ":\n";
                e[i].getData();
            }

            break;
        case 2:
            cout << "Enter Name: ";
            cin >> name;

            fl = 0;
            for (i = 0; i < n; i++)
            {
                if (name == e[i].getName())
                {
                    fl = 1;
                    break;
                }
            }

            if (fl == 1)
            {
                cout << "\nEmployee:\n";
                e[i].display();
            }
            else
            {
                cout << "\nNo Employee Found!";
            }

            break;
        default:
            cout << "\nInvalid Choice" << endl;
        }
    }
}