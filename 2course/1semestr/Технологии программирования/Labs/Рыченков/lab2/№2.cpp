#include <iostream>

using namespace std;

int main()

{
   setlocale(0,"Russian");
   int x;
   cout<<"������� �������������� ����� "<<endl;;
   cout<<"�������������� ����� - ";
   cin>>x;
   cout<<"�������� ����� - ";
   cout<<x%10;
   x/=10;
   cout<<x%10;
   x/=10;
   cout<<x%10;
   x/=10;
   cout<<x%10;
   x/=10;
   cout<<endl<<endl;
    return 0;
}
