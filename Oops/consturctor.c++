#include<iostream>
using namespace std;
class manoj
{
   public:
   int a;
   int b;
      manoj()
      {
         cout<<"i am constuructor "<<endl;
      }
      // manoj( int a ,int  b)
      // {
      //    this->a=a;
      //    this->b=b;
      // }
      manoj( int d ,int  e)
      {
         this->a=d;
         this->b=e;
      }
      manoj(manoj & temp)
      {
         cout<<temp.a+temp.b;
         this->a=temp.a;
         this->b=temp.b;
      }
      void print()
      {
         cout<<"value of a is = "<<a;
         cout<<"value of b is = "<<b;
      }

}; 
// this is the main section .
int main()
{
   manoj m1(10,30);
   manoj m2=m1;
   cout<<m1.a<<" ";
   cout<<m1.b;
   m2.print();
   return 0;
}
