#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class wheather
{
private:
        int day_of_month, HT, LT;
        int amountR, amountS;

public:
        wheather()
    
    {
                day_of_month = 99;
                HT = 999;
                LT = - 999;
                amountR = 0;
                amountS = 0;
            
    }
        void display()
    
    {
                cout << "\t" << HT << "\t" << LT << "\t" << amountR << "\t \t" << amountS;
            
    }
        void get(int d)
    
    {
                day_of_month = d;
                cout << "enter low temperature";
                cin >> LT;
                cout << "enter high temperature";
                cin >> HT;
                cout << "enter amount of rain";
                cin >> amountR;
                cout << "enter amount of snow";
                cin >> amountS;
            
    }
};
int main()
{
        wheather w[31];
        int i, n, k, y, d;
        char month[20];
        cout << "jan,feb,march,april,may,june,july,aug,sept,oct,nov,dec";
        cout << "\n enter name of month";
        cin >> month;
        cout << "howv many times to enter data";
        cin >> k;
        cout << "enter year of data";
        cin >> y;
        if  ((strcmp(month, "jan") == 0) || (strcmp(month, "march") == 0) || (strcmp(month, "may") == 0) || (strcmp(month, "july") == 0) || (strcmp(month, "aug") == 0) || (strcmp(month, "oct") == 0) || (strcmp(month, "dec") == 0))
    
    {
                n = 31;

        for (i = 0; i < k; i++)
        
{
                cout << "enter no. of date";
                cin >> d;
                w[d - 1].get(d);
            
}
    
    }
        else  if  ((strcmp(month, "april") == 0) || (strcmp(month, "june") == 0) || (strcmp(month, "sept") == 0) || (strcmp(month, "nov") == 0))
    
    {
                n = 30;

        for (i = 0; i < k; i++)
        
{
                cout << "enter value of day";
                cin >> d;
                w[d - 1].get(d);
            
}
    
    }
        else     
    {
                if  (y % 4 == 0)
        
        {
                        n = 29;
                    
        }
                else         
        {
                        n = 28;
                    
        }
        for (i = 0; i < k; i++)
        
{
                cout << "enter value of day";
                cin >> d;
                w[d - 1].get(d);
            
}
    
    }
        cout << "\n wheather report\n";
        cout << " data of month =" << month << "\t year=" << y;
        cout << "\n day"
         << "\t"
         << "HT"
         << "\t"
         << "LT"
         << "\t"
         << "amountRain"
         << "\t"
         << "amountsnow\n";
    for (i = 0; i < n; i++)
    
{
            cout << i + 1;
            w[i].display();
            cout << "\n";
        
}
    return 0;

    getch();
}
