#include<iostream>
#include<array>
using namespace std;
int main()
{
   int basic[3]={12,13,14};
   array<int,4> a={1,2,3,4};
   int size=a.size();
   cout<<size;
   cout<<a.at(2);
   cout<<a.empty();
   cout<<"front"<<a.front();
   int t=a.back();
   cout<<"\n"<<t;
   return 0;
}
