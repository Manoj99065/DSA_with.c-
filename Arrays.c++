
 #include<iostream>
#include<array>
using namespace std;

   int Arr(int a)
   {
      int *s = new int [a];
      for(int i=0;i<a;i++)
      {  cout<<"Enter the element in the array where position "<<i<<" = ";
         cin>>s[i];
      }
      
      // in this section we are display the array ?
      for(int i=0 ;i<a;i++)
      {
         
         cout<<s[i];
         if(i!=a-1)
         {
            cout<<",";
         }
      }
   }

int main()
{
   int i;
   cout<<"Enter the value of i = ";
   cin>>i;
   Arr(i);
   return 0;
}
