#include<iostream>
using namespace std;
class Manoj
{
   public:
   void arr1(int arr[],int size,int target)
   {
   int left=0;
   int right=size-1;
   int mid;
   while(left<=right){
   // mid=left+(right-left)/2;
   mid=left+(right-left)/2;
   cout<<endl<<"This is mid : "<<mid<<endl;
   if(arr[mid]==target)
   {
      cout<<"The target element is : " << arr[mid]<<endl;
      return ;
   }

   else if(target > arr[mid])
   {
      left=mid+1;
   }
   else
   {
      right=mid-1;
   }
   }
}
};

// This is main section in the program.
int main()
{
   int arr[]={12,42,44,66,75,81,92,100};
   int size=sizeof(arr)/sizeof(arr[0]);
   int target=81;
   Manoj m1;
   m1.arr1(arr,size,target);
   return 0;
}
