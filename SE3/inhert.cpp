#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

class Person
{
public:
    string name, dob, blood;

    void getPerson()
    {
        cout << "Enter Person Name, DOB, Blood Group:\n";
        cin >> name >> dob >> blood;
    }
};

class Health
{
public:
    int height, weight;

    void getHealth()
    {
        cout << "Enter Height & Weight:\n";
        cin >> height >> weight;
    }
};

class Details
{
public:
    string address;

    int ins_no;

    void getDetails()
    {
        cout << "Enter Insuarance No & Address:\n";
        cin >> ins_no >> address;
    }
};

class Liscense : public Person, public Health, public Details
{
    int tel;
    string drivlic;

public:
    void getLiscenceDetails()
    {
        getPerson();
        getHealth();
        getDetails();
        cout << "Enter Telephone & Driving License:\n";
        cin >> tel >> drivlic;
        cout << "\nEntry Added!\n";
    }
    void display()
    {
        cout << "\n\nName: " << name << "\nDOB: " << dob << "\nBlood Group: " << blood << "\nHeight: " << height << "\nWeight: " << weight << "\nInsurance No: " << ins_no << "\nAddress: "
             << address << "\nTelephone: " << tel << "\nDriving Liscense No: " << drivlic;
    }
};

int main()
{

    Liscense l[10];
    int i, n, ins, fl, ch;
    cout << "License App:\n";
    cout << "Enter Number of Entries: ";
    cin >> n;

    while (1 > 0)
    {
        cout << "\nSelect Operation:\n1.Add Entry\n2.Edit Entry\n3.Search\n4.Delete\n5.Display\n";
        cin >> ch;

        switch (ch)
        {
        case 1:

            for (i = 0; i < n; i++)
            {
                cout << "Entry " << i + 1 << ":\n";
                l[i].getLiscenceDetails();
            }

            break;
        case 2:
            cout << "Enter Insuarance No: ";
            cin >> ins;
            fl = 0;
            for (i = 0; i < n; i++)
            {
                if (l[i].ins_no == ins)
                {
                    fl = 1;
                    break;
                }
            }

            if (fl == 1)
            {
                l[i].getLiscenceDetails();
            }
            else
            {
                cout << "\nInvalid Insuarance No!\n";
            }

            break;
        case 3:
            cout << "Enter Insuarance No: ";
            cin >> ins;
            fl = 0;
            for (i = 0; i < n; i++)
            {
                if (l[i].ins_no == ins)
                {
                    fl = 1;
                    break;
                }
            }

            if (fl == 1)
            {
                l[i].display();
            }
            else
            {
                cout << "\nNo Entries Found!\n";
            }

            break;
        case 4:
            cout << "Enter Insuarance No: ";
            cin >> ins;
            fl = 0;
            for (i = 0; i < n; i++)
            {
                if (l[i].ins_no == ins)
                {
                    fl = 1;
                    break;
                }
            }

            if (fl == 1)
            {
                for (i = i; i < n; i++)
                {
                    l[i] = l[i + 1];
                }
                n--;
            }
            else
            {
                cout << "\nnInvalid Insuarance No!\n";
            }
            break;
        case 5:
            for (int i = 0; i < n; i++)
            {
                l[i].display();
            }
            break;

        default:
            break;
        }
    }

    getch();

    return 0;
}