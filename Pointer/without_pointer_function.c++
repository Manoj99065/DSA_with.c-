#include<iostream>
using namespace std;
class manoj
{
   public:
   void hello()
   {
      cout<<"i am without parameter function \n";
   }
   int squre(int x)
   {
     x=x*x;
     return x;
   }
};
// This is a main section in the program.
int main()
{
   int x=10;
   manoj m1;
   m1.hello();
   int squre1=m1.squre(x);
   cout<<"The squre of the number is = "<<squre1;
   return 0;
}
