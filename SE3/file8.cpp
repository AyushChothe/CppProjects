#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
using namespace std;
#pragma region
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
#pragma endregion
int main()
{
    fstream file;
    Employee e;
    int i, fl, ch;
    string name;

    while (1 > 0)
    {
        cout << "\n--------------------\nSelect Operation:\n1.Add Entry\n2.Display\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            file.open("emps.txt", ios::app);

            e.getData();

            file.write((char *)&e, sizeof(e));

            cout << "\nEntry Added!";

            file.close();
            break;
        case 2:
            file.open("emps.txt", ios::in);
            cout << "Enter Name:\n";

            cin >> name;

            file.read((char *)&e, sizeof(e));

            while (!file.eof())
            {
                if (name == e.getName())
                {
                    e.display();
                    cout << "Record Found!";
                    break;
                }

                file.read((char *)&e, sizeof(e));
            }

            file.close();
            break;
        default:
            cout << "\nInvalid Choice" << endl;
        }
    }
}