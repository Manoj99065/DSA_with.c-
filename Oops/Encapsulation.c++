#include<iostream>
using namespace std;
class manoj
{
   private:
   string name;
   int age=10;
   int height;

   public:
   int getAge()
   {
      return this->age;
   }

};
int main()
{
   manoj m1;
   cout<<m1.getAge();
   return 0;
}
