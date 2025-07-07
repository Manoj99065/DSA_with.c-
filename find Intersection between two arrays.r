#include<iostream>
using namespace std;
int main()
{
  int i[]={10,20,10,20,20,50,30,3};
  int j[]={10,3,45,20,50,10,10,3};
  
  int size1=sizeof(i)/sizeof(i[0]);
  int size2=sizeof(j)/sizeof(j[0]);
  int *z=new int [size1];
  int y=0;
  int m;
  
  for(int l=0;l<size1;l++)
  
  {
    int a;
   m=i[l];
   for(int k=0;k<l;k++)
   {
   if(j[k]==m){
   a=j[k];
   
  z[y]=a;
  y++;
  }}}
for(int ii=0;ii<y;ii++){
  // { cout<<y <<endl;
    cout<<z[ii];
    if(ii!= y-1)
    {
      cout<<",";

    }
  }
  return 0;
}
