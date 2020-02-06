
#include<iostream>
#include<string.h>
# include<fstream>
using namespace std;
class base1
{
 protected:
  char name[10],addr[10],ph[11],dat[20];
 public:
     void get_data1()
	 {
	  cout<<"\n\tNAME:";
	  cin>>name;
	  cout<<"\n\tADDRESS:";
	  cin>>addr;
	  cout<<"\n\tPHONE NO:";
	  cin>>ph;
	  cout<<"\n\tBIRTH DATE:";
	  cin>>dat;
	 }
     void put_data1()
	 {
	  cout<<"\n\n\tNAME:"<<name;
	  cout<<"\n\n\tADDRESS:"<<addr;
	  cout<<"\n\n\tPHONE NO:"<<ph;
	  cout<<"\n\n\tBIRTH DATE:"<<dat;
	 }
};

class base2
{
 protected:
 float per1,per2,per3;
 public:
     void get_data2()
	{
	 cout<<"\n\t10th PERCENT:";
	 cin>>per1;
	 cout<<"\n\t12th PERCENT:";
	 cin>>per2;
	 cout<<"\n\tGRADUATION PER:";
	 cin>>per3;
	}
    void put_data2()
	{
	 cout<<"\n\n\t10th PERCENT:"<<per1;
	 cout<<"\n\n\t12th PERCENT:"<<per2;
	 cout<<"\n\n\tGRADUATION PERCENT:"<<per3;
	}
};

class base3
{
 protected:
 char pd[20],semi[10],hbs[15],spts[10];
 public:
    void get_data3()
    {
     cout<<"\n\tPROJECT DONE NAME:";
     cin>>pd;
     cout<<"\n\tSEMINAR:";
     cin>>semi;
     cout<<"\n\tHOBBIES:";
     cin>>hbs;
     cout<<"\n\tSPORTS:";
     cin>>spts;
    }
    void put_data3()
    {
     cout<<"\n\n\tPROJECT DONE:"<<pd;
     cout<<"\n\n\tSEMINAR:"<<semi;
     cout<<"\n\n\tHOBBIES:"<<hbs;
     cout<<"\n\n\tSPORTS:"<<spts;
    }
};

class derived :public base1,public base2,public base3
{
 public:
     void get_data4()
     {
      get_data1();
      get_data2();
      get_data3();
     }
     void put_data4()
     {
      put_data1();
      put_data2();
      put_data3();
     }
     char *get_name()
     {
      return(name);
     }
};

int main()
{
 char s[10];
 int ch,flag;
 derived d;
 fstream file;
 do
 {

  cout<<"\n\t1:insert\n\n\t2:display\n\n\t3:exit";
  cout<<"\n\nENTER U R CHOICE:";
  cin>>ch;
  switch(ch)
  {
   case 1:
	file.open("biodata.txt",ios::out);
	d.get_data4();
	file.write((char*)&d,sizeof(d));
	file.close();
	  break;
   case 2:cout<<"\n\n\tENTER NAME:";
	  cin>>s;
	  flag=0;
	  file.open("biodata.txt",ios::in);
	  while(file.read((char*)&d,sizeof(d)))
	  {
	   if(strcmp(d.get_name(),s)==0)
	   {
	   cout<<"\n\t/******BIO DATA******/";
	   d.put_data4();
	   flag=1;
	   break;
	   }
	  }
	  file.close();
	  if(flag==0)
	  cout<<"not found ";
	  break;
  }
 
 }while(ch!=3);
return 0;
}





