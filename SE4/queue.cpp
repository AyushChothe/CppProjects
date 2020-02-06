#include <iostream>
#include <conio.h>
using namespace std;

template <class DT = string>
class Queue
{
    typedef struct node
    {
        DT data;
        node *next = NULL;
    } node;

    node *front, *rear, *p;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void push(DT data)
    {
        p = new node;
        p->data = data;

        if (front == NULL)
        {
            front = new node;
            rear = new node;
            front = p;
            rear = p;
        }
        else
        {
            rear->next = p;
            rear = p;
        }
    }

    DT pop()
    {
        DT data;
        if (front != NULL)
        {
            p = new node;
            p = front;
            data = p->data;
            front = front->next;
            delete p;
        }
        return data;
    }

    void display()
    {
        p = new node;
        p = front;
        while (p != NULL)
        {
            DT d = p->data;
            d.display();
            cout << " > ";
            p = p->next;
        }
        cout << "NULL";
    }
};

class Patient
{
    int id;
    string name, disease;

public:
    Patient() {}
    Patient(int i, string n, string d)
    {
        id = i;
        name = n;
        disease = d;
    }
    void get(int i)
    {
        id = i;
        cout << "Name: ";
        cin >> name;
        cout << "Disease: ";
        cin >> disease;
    }
    void display()
    {
        cout << "[" << id << ". " << name << " : " << disease << "]";
    }
};

int main()
{
    Queue<Patient> q;
    Patient p;
    int i = 1;

    while (0 < 1)
    {
        int ch;
        cout << "\nEnter a Choice:\n1.Add Patient\n2.Remove Patient\n3.Display Patient\n4.Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            p.get(i);
            q.push(p);
            p.display();
            
            cout << "\nPatient #" << i << " Added!\n*************";
            i++;
            break;
        case 2:
            q.pop();
            cout << "\nPatient Removed!\n*************";
            break;
        case 3:
            q.display();
            cout << "\n*************";
            break;
        default:
            exit(0);
        }
    }
    getch();
    return 0;
}