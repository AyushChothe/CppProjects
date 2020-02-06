#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

typedef struct node
{
	string data;
	node *next;
} node;

class Stack
{

public:
	node *head, *p;

	int max;
	int top;

	Stack()
	{
		head = new node;
		p = new node;
		max = 10;
		top = -1;
	}

	void push(node *el)
	{

		if (head == NULL)
		{
			head = el;
			top++;
		}
		else
		{
			p = head;
			while (p->next != NULL)
			{
				p = p->next;
			}

			p->next = el;
			top++;
		}
	}

	string pop()
	{
		string data;

		if (head != NULL)
		{

			p = head;

			while (p->next != NULL)
			{
				p = p->next;
			}

			data = p->data;
			delete p;
			p = new node;
			top--;
		}
		return data;
	}

	void display()
	{
		node *p;

		p = head;
		while (p->next != NULL)
		{
			p = p->next;
			cout << p->data;
		}
		cout << "\n";
	}
};

bool isOperand(char o)
{
	return !(o == '+' || o == '-' || o == '*' || o == '/' || o == '%' || o == '^' || o == '$');
}

string calc(string a, string b, char f)
{
	return (a + f + b);
}

int main()
{

	Stack s;
	int ch;
	string eqn;

	while (1 > 0)
	{

		cout << "\nEnter Choice\n1.Postfix Evaluation\n2.Prefix Evaluation\n3.Exit\n";
		cin >> ch;

		switch (ch)
		{
		case 1:
			cout << "Enter Equation: ";
			cin >> eqn;

			for (int i = 0; i < eqn.length(); i++)
			{
				node *el = new node;

				if (isOperand(eqn[i]))
				{
					el->data = eqn[i];
					s.push(el);
				}
				else
				{
					string op1, op2;
					//op2=s.pop();
					//op1=s.pop();

					//el->data = (op1+eqn[i]+op2);
					cout << s.pop() << s.pop() << s.pop();
					//s.push(el);
				}
			}
			cout << "\nYour Evaluation is: ";
			s.display();

			break;
		}
	}

	return 0;
}
