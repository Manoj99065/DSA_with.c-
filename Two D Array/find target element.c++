#include<iostream>
using namespace std;

 bool search(int  arr[][4],int target,int size , int size1)
      {
       
        for(int i=0;i<size;i=i+1)
        {
          for(int j=0;j<size1;j=j+1)
          {
          if(target==arr[i][j])
          {
            return 1;          
          } 
         }
      }
   return 0;
   }
int main()
{
   int size=3;
   const int size1=4;
   int j=0;
   int arr[size][size1]={{1,2,3,4},{6,7,8,6},{6,5,4,4}};
   
   int target;
   cout<< "Enter the target elment :- ";
   cin>>target;
   if(search(arr,target,size,size1))
   {
     cout<<"Element exit in the code .";
   } 
   else
   {
      cout<<"Element not exit in the code";
   }


   return 1;
}
