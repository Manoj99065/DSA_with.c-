#include<iostream>
using namespace std;
int main()
{  
   int mul=1;
   int i=5;
   for(int j=i;j>=1;j--)
   {
   mul=j*mul;
   }
   cout << mul;
}
