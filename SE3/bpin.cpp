#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

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

long findAll(string str, char find)
{
    long count = 0;

    for (long i = 0; i < str.length(); i++)
    {
        if (str.at(i) == find)
        {
            count++;
        }
    }

    return count;
}

int main()
{

    string pins = "IIXXIIXXIIXXXXIIIXXIXX";

    cout << "Bowling Pins Original: " << pins << endl;

    pins = replaceAll(replaceAll(pins, "II", "I"), "XX", "X");
    cout << "Bowling Pins Compressed: " << pins << endl;

    cout << "I: " << findAll(pins, 'I') << endl;
    cout << "X: " << findAll(pins, 'X') << endl;
    getch();
    return 0;
}