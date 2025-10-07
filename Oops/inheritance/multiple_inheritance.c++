#include<iostream>
using namespace std;
class single
{
   public:
   string name="manoj";
   int age;
   long long roll_no;
};

class child_class 
{
 protected:
 string cast;
 void display()
 {
   cout<<"my cast is "<<cast<<endl;
 }
 
 public:
 void getcast()
 {
   display();
 }
 
 void setcast(string c)
 {
   this->cast=c;
 }
};


class child_class_1:public  single , public child_class
{
    public:
    char t='t';
    string name="Manoj Thakur";
};

// this is main section in the programming.
int main()
{
 child_class_1 c1;
//  c1.name="manoj";
 c1.age=22;
 c1.roll_no=230010139015;
 c1.setcast("rajput");
 cout<<c1.single::name<<endl;
 cout<<c1.age<<endl;
 cout<<c1.roll_no<<endl;
 c1.getcast();
 cout<<c1.name;
 return 0;
};
