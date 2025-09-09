#include<iostream>
#include<algorithm>
using namespace std;
class manoj
{
   public:
   void sort(int *arr,int size,int size1)
   {
   // cout<<size;
    if(size<0)
    {
      return ;
    }
    sort(arr,size-1,size1);
    int k=size;
   //  cout<<k;
    for(int i=size+1;i<size1;i++)
    {
     if(arr[i]<arr[k])
     {
      k=i;
     }
    }
      swap(arr[size],arr[k]);
   }
   
};

// This is a main section in the program.
int main()
{
 int arr[]={10,3,2,1,5};
 int size=sizeof(arr)/sizeof(arr[0]);
 manoj m1;
 m1.sort(arr,size-1,size);
 cout<<endl;
 for(int i=0;i<size;i++)
 {
   cout<<arr[i];
   if(i!=size-1)
   {
      cout<<",";
   }
 }
 return 0;
}
