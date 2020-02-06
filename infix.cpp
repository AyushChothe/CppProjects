#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
using namespace std;

typedef struct node
{
    string data;
    node *next = NULL;
} node;

class Stack
{

    node *top, *p;

public:
    Stack()
    {
        top = NULL;
    }

    void push(string d)
    {
        p = new node;
        p->data = d;
        p->next = NULL;

        if (top == NULL)
        {
            top = new node;

            top = p;
        }
        else
        {
            p->next = top;
            top = p;
        }
    }

    string pop()
    {
        p = new node;
        p = top;
        string data;

        if (p != NULL)
        {
            data = p->data;
            top = top->next;
            p->next = NULL;

            return data;
        }
    }

    string peek()
    {
        return top != NULL ? top->data : "\0";
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void display()
    {
        p = new node;
        p = top;
        while (p != NULL)
        {
            cout << p->data << " > ";
            p = p->next;
        }
    }
};

Stack s;

bool isOperand(char o)
{
    return !(o == '+' || o == '-' || o == '*' || o == '/' || o == '%' || o == '^' || o == '$' || o == '(' || o == ')');
}

int checkPre(char op)
{
    switch (op)
    {
    case '^':
    case '$':
        return 4;
        break;
    case '%':
        return 3;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        return 0;
    }
}

string calc(string op1, string f, string op2)
{
    switch (f.at(0))
    {
    case '+':
        return to_string(stoi(op1) + stoi(op2));
        break;
    case '-':
        return to_string(stoi(op1) - stoi(op2));
        break;
    case '*':
        return to_string(stoi(op1) * stoi(op2));
        break;
    case '/':
        return to_string(stoi(op1) / stoi(op2));
        break;
    case '%':
        return to_string(stoi(op1) % stoi(op2));
        break;
    case '^':
    case '$':
        return to_string(int(pow(stoi(op1), stoi(op2))));
        break;

    default:
        break;
    }
}

string replace(string str, string replace, string with)
{
    string newS;

    if (replace != with)
    {

        for (int i = 0; i < str.find(replace); i++)
        {
            newS += str.at(i);
        }

        newS += with;

        for (int i = str.find(replace) + replace.length(); i < str.length(); i++)
        {
            newS += str.at(i);
        }

        return newS;
    }
    else
    {
        return str;
    }
}

string replaceAll(string str, string rep, string with)
{
    string newStr = str;

    if (rep != with)
    {

        while (newStr.find(rep) < newStr.length())
        {
            newStr = replace(newStr, rep, with);
        }
    }

    return newStr;
}

string reverse(string str)
{

    string newStr = "";

    for (int i = str.length() - 1, j = 0; i >= 0; i--, j++)
    {
        if (str[i] == '(')
        {

            newStr += ')';
        }
        else if (str[i] == ')')
        {
            newStr += '(';
        }
        else
        {
            newStr += str[i];
        }
    }

    return newStr;
}

string InfixToPostfix(string eqn)
{
    string op;

    for (int i = 0; i < eqn.length(); i++)
    {
        char x = eqn[i];
        string c = string(1, x);

        if (isOperand(x))
        {
            op += x;
        }
        else if (x == '(')
        {
            s.push("(");
        }
        else if (x == ')')
        {
            while (s.peek() != "\0" && s.peek() != "(")
            {
                op += s.pop();
            }
            if (s.peek()[0] == '(')
            {
                s.pop();
            }
        }
        else
        {
            while (s.peek() != "\0" && checkPre(x) <= checkPre(s.peek()[0]))
            {
                op += s.pop();
            }
            s.push(c);
        }
    }
    while (s.peek() != "\0")
    {
        op += s.pop();
    }
    return op;
}

string InfixToPrefix(string eqn)
{
    //Reverse String And Replace
    return reverse(InfixToPostfix(reverse(eqn)));
}

string PostfixEvaluation(string eqn)
{
    string op1, op2;

    for (int i = 0; i < eqn.length(); i++)
    {
        char x = eqn[i];
        string c = string(1, x);

        if (isOperand(x))
        {
            s.push(c);
        }
        else
        {
            op2 = s.peek();
            s.pop();
            op1 = s.peek();
            s.pop();

            s.push(calc(op1, c, op2));
        }
    }

    return s.pop();
}

string PrefixEvaluation(string eqn)
{
    string op1, op2;

    eqn = reverse(eqn);

    for (int i = 0; i < eqn.length(); i++)
    {
        char x = eqn[i];
        string c = string(1, x);

        if (isOperand(x))
        {
            s.push(c);
        }
        else
        {
            op1 = s.peek();
            s.pop();
            op2 = s.peek();
            s.pop();

            s.push(calc(op1, c, op2));
        }
    }

    return s.pop();
}

int main()
{

    int ch;
    string exp;

    while (0 < 1)
    {
        s = Stack();
        cout << "\n**********\nEnter Choice:\n1.Infix to Postfix\n2.Infix to Prefix\n3.Postfix Evaluation\n4.Prefix Evaluation\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter Infix Expression: ";
            cin >> exp;
            cout << InfixToPostfix(exp);
            break;
        case 2:
            cout << "Enter Infix Expression: ";
            cin >> exp;
            cout << InfixToPrefix(exp);
            break;
        case 3:
            cout << "Enter Postfix Expression: ";
            cin >> exp;
            cout << PostfixEvaluation(exp);
            break;
        case 4:
            cout << "Enter Prefix Expression: ";
            cin >> exp;
            cout << PrefixEvaluation(exp);
            break;
        default:
            exit(0);
            break;
        }
    }

    getch();
    return 0;
}