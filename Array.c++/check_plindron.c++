#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
class manoj
{  public:
   char array(char arr[],int size1)
   {
   int size=size1;
   string m="";
   string s="";
    int left=0;
    int t=size1;
    for(int i=0;i<t;i=i+1)
    {
      arr[i]=tolower(arr[i]);
      
      if(arr[i]==' ' || arr[i]==',' || arr[i]=='.' || arr[i]=='-' || arr[i]=='_' || arr[i]=='/' || arr[i]=='<'|| arr[i]=='>' || arr[i]=='*' || arr[i]==']' || arr[i]=='[' )
      {
         for(int j=i;j<t;j=j+1)
         {  
            char temp= arr[j];
            arr[j]=arr[j+1];
            size=size-1;
         }
         m=m+arr[i];
         t=t-1;
      }
      else
      {
         m=m+arr[i];
      }
    }
   // cout<<"This is my array :- "<<arr;
   //  int right=strlen(arr);

    int H=strlen(arr);
    int right=H-1;
    while(left<right)
    {
      swap(arr[left],arr[right]);
      left=left+1;
      right=right-1;
    }
   //  cout<<endl<<"This is my array1 :- "<<arr <<strlen(arr)<<endl;
   //  int this section we are put the element of the array into string and name of string s.
   
   for(int i=0;i<H;i++)
   {
   s=s+arr[i];
   }
   cout<<"This is m "<<m.length()<<" "<<m<<endl;
   
   cout<<"This is s "<<s.length()<<" "<<s<<endl;
   // // cout<<endl<<m<<endl;
   // // in this section we are compare this.
   if(s==m)
   {
      cout<<endl<<"The string is palindron "<<endl;
   }
   else
   {
      cout<<"The string is not palidron "<<endl;
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
   return 0;
}
