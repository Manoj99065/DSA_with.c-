#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void permuation(vector<int>nums,int size,vector<vector<int>>&ans,int index)
{
  // here we are declare base case.
  if(index>=size)
  {
   ans.push_back(nums);
   return ;
  }
  // here we are do some operation .
  for(int i=index;i<size;i++)
  {
   swap(nums[i],nums[index]);
   permuation(nums,size,ans,index+1);
   swap(nums[i],nums[index]);
  }

}

vector<vector<int>>solve(vector<int>nums)
{
   vector<vector<int>>ans;
   int size=nums.size();
   int index=0;
   permuation(nums,size,ans,index);
   return ans;
}

int main()
{
   vector<int>nums={1,2,3};
   vector<vector<int>>result=solve(nums);
   for(const auto &run:result)
   {
      for(int val: run)
      {
      cout<< val <<" ";
     }
     cout<<endl;
   }
   cout<<endl;
   return 0;
}
