#include<iostream>
using namespace std;

class manoj
{
   public:
   int arr(int arr[],int size,int target)
   {
      
      for(int i=0;i<size;i++)
      {
         if(arr[i]==target)
         {
         cout<< arr[i];
         }
      }
   }
};

// This is a main section in the program.
int main()
{
   int i;
   int arr[]={1,24,53,64523,235};
   int size =5;
   int target=53;
   manoj r1;
   r1.arr(arr,size,target);
   return 0;

}
