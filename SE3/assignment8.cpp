
#include <string.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class student
{
private:
	int Roll_no;
	char name[10];
	float age;

public:
	void input()
	{
		cout << "\nEnter name:";
		cin >> name;
		cout << "\nEnter roll no:";
		cin >> Roll_no;
		cout << "\nEnter age:";
		cin >> age;
	}
	void show()
	{
		cout << "Name:" << name << endl;
		cout << "Roll:" << Roll_no << endl;
		cout << "Age:" << age << endl;
	}
	char *getn()
	{
		return name;
	}
};
student s;

fstream fil;
int main()
{
	ofstream o;
	char ch = 'y';
	char n[100];
	int opt;
	do
	{
		cout << "\n1:create\n2:display\n3:display particular\n4:Add new record\n5:modify\n6:Delete";
		cout << "\nEnter your choice:";
		cin >> opt;
		switch (opt)
		{
		case 1:
			fil.open("binary.dat", ios::out | ios::binary);
			while (ch == 'y' || ch == 'Y')
			{
				s.input();
				fil.write((char *)&s, sizeof(s));
				cout << "Do you want to continue:";
				cin >> ch;
			}
			fil.close();
			cout << "Display Main Menu" << endl;
			break;

		case 2:
			fil.open("binary.dat", ios::in | ios::binary);
			if (!fil)
			{
				cout << "File not Found";
				exit(0);
			}
			else
			{
				fil.read((char *)&s, sizeof(s));
				while (!fil.eof())
				{
					s.show();
					fil.read((char *)&s, sizeof(s));
				}
			}
			fil.close();
			cout << "Display Main Menu";

			break;
		case 3:
			cout << "\nEnter the name you want to search:";
			cin >> n;
			fil.open("binary.dat", ios::in | ios::binary);
			if (!fil)
			{
				cout << "File not Found";
				exit(0);
			}
			else
			{
				fil.read((char *)&s, sizeof(s));
				while (!fil.eof())
				{
					if (strcmp(n, s.getn()) == 0)
					{
						s.show();
					}
					else
					{
						cout << "\nPress Any Key....For Search";
					}
					fil.read((char *)&s, sizeof(s));
				}
			}
			fil.close();
			break;
		case 4:
			fil.open("binary.dat", ios::in | ios::app | ios::ate | ios::binary);
			while (ch == 'y' || ch == 'Y')
			{
				s.input();
				fil.write((char *)&s, sizeof(s));
				cout << "Want to Continue.....";
				cin >> ch;
			}
			fil.close();
			cout << "Display Main Menu" << endl;
			break;
		case 5:
			cout << "Enter Name that should be searched:";
			cin >> n;
			fil.open("binary.dat", ios::in | ios::out | ios::binary);
			if (!fil)
			{
				cout << "File not Found";
				exit(0);
			}
			else
			{
				fil.read((char *)&s, sizeof(s));
				while (!fil.eof())
				{
					if (strcmp(n, s.getn()) == 0)
					{
						fil.seekg(0, ios::cur);
						cout << "Enter New Record.." << endl;
						s.input();
						int pos = fil.tellg();
						fil.seekp(pos - sizeof(s), ios::beg);
						fil.write((char *)&s, sizeof(s));
					}
					else
					{
						cout << "Press Any Key....For Search" << endl;
					}
					fil.read((char *)&s, sizeof(s));
				}
			}

			fil.close();
			cout << "Display Main Menu" << endl;

			break;
		case 6:
			cout << "Enter Name that should be Deleted :";
			cin >> n;

			o.open("new.dat", ios::out | ios::binary);
			fil.open("binary.dat", ios::in | ios::binary);
			if (!fil)
			{
				cout << "File not Found";
				exit(0);
			}
			else
			{
				fil.read((char *)&s, sizeof(s));
				while (!fil.eof())
				{
					if (strcmp(n, s.getn()) != 0)
					{
						o.write((char *)&s, sizeof(s));
					}
					else
					{
						cout << "Press Any Key....For Search" << endl;
					}
					fil.read((char *)&s, sizeof(s));
				}
			}
			o.close();
			fil.close();
			remove("binary.dat");
			rename("new.dat", "binary.dat");

			cout << "Display Main Menu" << endl;

			break;
		default:
			cout << "Invailed choice";
		}
	} while (opt != 0);
	return 0;
}
