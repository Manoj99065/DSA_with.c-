#include<iostream>
using namespace std;
int main()
{
   float a,b;
   char z;
   cout << "Enter the value of a = ";
   cin>>a;
   cout << "Enter the operations ";
   cin>>z;
   cout<<"Enter the value of b = ";
   cin>>b;

   // in this section we are perform basic operation about this .
   if(z== '+')
   {
      cout << "Sum of a and b = "<<a+b<<endl;
   }
   else if(z=='-')
   {
      cout << "subtraction of number a and b  = "<<a-b<<endl;
   }
   else if(z=='*')
   {
      cout << "Multiplication of a and b "<<a*b<<endl;
   }
   else if(z=='/')
   {
      cout<<"Divison of a and b "<<a/b<<endl;
   }
   else if(z=='%')
   {
      cout<<"Modules of a and b "<< int(a) % int(b) <<endl;
   }
   else
   {
      cout<<"Not operation perform about a and b ";
   }
   

}
