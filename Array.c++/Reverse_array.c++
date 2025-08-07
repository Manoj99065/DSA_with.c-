#include<iostream>
using namespace std;
class manoj
{
   public:
   void array(int arr[],int size)
   {
      int left=0;
      int right=size-1;
      while(left<=right)
      {
         {
         swap(arr[left],arr[right]);
         left=left+1;
         right=right-1;
               }
      }
      // in this section we are display element.
      for(int i=0;i<size;i++)
      {
         cout<<arr[i];
         if(i!=size-1)
         {
            cout<<",";
         }
      }
      
   }
};

// this is the main section so.
int main()
{
   int arr[]={10,20,30,40,50,60};
   int size=sizeof(arr)/sizeof(arr[0]);
   manoj m1;
   m1.array(arr,size);
   return 0;
}
