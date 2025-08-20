#include<iostream>
#include<vector>
using namespace std;
class manoj
{
   public:
   // vector<int> HCf(vector<int> & arr,int size)
   void HCF(int i,int j)
   {  vector<int>v;
      int small;
      if(i<j)
      {
         small=i;
      }
      else
      {
         small=j;
      }
      for(int k=2;k<=small;k=k+1)
      {
         if(i%k==0 && j%k==0)
         {
            v.push_back(k);
         }
      }
      int size=v.size();
      int greater=v[0];
      for(int i=0;i<size;i++)
      {
         if(v[i]>greater)
         {
           greater=v[i];
         }
      }
      cout<<"larget highest command divisor is ="<<greater;
   }

};
int main()
{  int i,j=0;
   cout<<"Enter the value of number 1 = ";
   cin>>i;
   cout<<"Enter the value of number 2 = ";
   cin>>j;
   manoj m1;
   m1.HCF(i,j);
   return 0;
}
