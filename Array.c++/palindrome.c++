#include<iostream>
#include<cstring>
using namespace std;
class manoj
{  public:
   // void Swap(char a, char b)
   // {
   //    char temp=a;
   //    a=b;
   //    b=a;
   // }
   void array(char arr[],int size)
   {
    int left=0;
    int right=size-1;
    
    while(left<=right)
    {
      swap(arr[left],arr[right]);
      left=left+1;
      right=right-1;
    }
   }
};

int main()
{
   char *name=new char[100];
   cout<<"Enter you own name :- ";
   cin>>name;
   string Name=name;
   int len=strlen(name);
   // cout<<len;
   manoj m1;
   m1.array(name,len);
   // cout<<name;
   // cout<<Name;
   if(Name==name)
   {
      cout<<"THis is palidron";
   }
   else
   {
      cout<<"The given name is not palidron";
   }
   
   return 0;
}
