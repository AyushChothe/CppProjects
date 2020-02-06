#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

class Book
{
public:
    static int sTrans, fTrans;
    int id;
    char title[50];
    char author[50];
    char publisher[50];
    int price, stock;

    void add(int i)
    {
        id = i;
        cout << "Title: ";
        cin >> title;

        cout << "Author: ";
        cin >> author;

        cout << "Publisher: ";
        cin >> publisher;

        cout << "Price: ";
        cin >> price;

        cout << "Stock: ";
        cin >> stock;
    }

    int search(char t[], char a[])
    {
        if (strcmp(title, t) == 0 && strcmp(author, a) == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        };
    }

    void update(int stk)
    {
        if (stock > 0 && stock >= stk)
        {
            Book::sTrans++;
            stock -= stk;
            cout << "Books are Available!" << endl;
            cout << "Total Amount " << price << " X " << stk << " = " << price * stk << endl;
        }
        else
        {
            Book::fTrans++;
            cout << "Books are Not Available!";
        }
    }

    void display()
    {
        cout << "\nId: " << id;

        cout << "\nTitle: " << title;

        cout << "\nAuthor: " << author;

        cout << "\nPublisher: " << publisher;

        cout << "\nPrice: " << price;

        cout << "\nStock: " << stock << endl;
    }
};

int Book::sTrans;
int Book::fTrans;

int main()
{

    Book b[5];
    int n, ch, id, stk, found = -1;
    char title[50], author[50];

    cout << "Welcome to Book Store!\n";
    cout << "How many Books: ";
    cin >> n;

    while (1 > 0)
    {

        cout << "--------------------\nEnter Choice:" << endl;
        cout << "1.Add Details" << endl;
        cout << "2.Search" << endl;
        cout << "3.Buy Book" << endl;
        cout << "4.Record of Successful Transactions" << endl;
        cout << "5.Record of Failed Transactions" << endl;

        cin >> ch;

        switch (ch)
        {
        case 1:

            for (int i = 0; i < n; i++)
            {
                cout << "\nBook " << i + 1 << ":" << endl;
                b[i].add(i + 1);
            }

            break;
        case 2:

            cout << "\nEnter Title: ";
            cin >> title;
            cout << "Enter Author: ";
            cin >> author;
            found = -1;
            for (int i = 0; i < n; i++)
            {
                if (b[i].search(title, author) == 1)
                {
                    found = i;
                }
            }

            if (found > -1)
            {
                cout << "Book Found!" << endl;
                b[found].display();
            }
            else
            {
                cout << "Book Not Found!" << endl;
            }

            break;
        case 3:
            cout << "Enter Book Id to Buy: ";
            cin >> id;
            cout << "Enter Count: ";
            cin >> stk;

            if (id > 0 && id <= n)
            {

                b[id - 1].update(stk);
            }
            else
            {
                cout << "\nInvalid Id!\n";
            }

            break;
        case 4:
            cout << "Successful Transactions: " << Book::sTrans << endl;
            break;
        case 5:
            cout << "Failed Transactions: " << Book::fTrans << endl;
            break;

        default:
            break;
        }
    }

    return 0;
}