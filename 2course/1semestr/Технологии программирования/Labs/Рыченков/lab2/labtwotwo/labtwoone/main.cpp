#include <iostream>
#include <math.h>
#include "conio.h"
#include <clocale>

using namespace std;

int main()
{
    setlocale(0,"");
    unsigned int a,b,c,d;
 cout<<"������� ����� ��������"<<endl;
 cin>>a;
 if(a<361)
 {
     b=a*2;
     c=b/60;
     d=b%60;
     cout<<c<<" ����� "<<d<<" ����� "<<endl;
 }else
 cout<<" ��� ������ �����"<<endl;


    return 0;
}
