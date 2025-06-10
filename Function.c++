#include<iostream>
using namespace std;
int sum (int a)
{
   int j=0;
   for(int i=1;i<=a;i++)
   {
      j=j+i;
      // cout<<j;
   }
   return j;
}
int main()
{ 
   int a;
   cout<<"Enter the number = ";
   cin>>a;
   cout<<"Result of given n number sum = "<<sum (a);
return 0;
}
