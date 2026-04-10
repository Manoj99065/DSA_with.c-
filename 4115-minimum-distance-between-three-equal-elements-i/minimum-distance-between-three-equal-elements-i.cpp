// class Solution {
// public:
//     int minimumDistance(vector<int>& nums) {
//     int sum=INT_MAX;
//     for(int i=0; i<nums.size();i++)
//     {
//         for(int j=nums.size()-1 ; n>i  ;  k--)
//         {
            
//           if(nums[i]==nums[j] && nums[j]==nums[k] && nums[k]==nums[i] && k>j)
//           {
//             // int k=abs(nums[i-1]+nums[i]) + abs(nums[i]-nums[j]) + abs(nums[j]-nums[i-1]);
          
//             int k=abs(i-j) + abs(j-k) + abs(k-i);
//             if(k<sum)
//             {
//                 sum=k;
//             }
//           }
//         }
//     }
//     if(nums.size()<3)
//     {
//         return -1;
//     }
//      return sum;   
//     }
// };


class Solution {
public:
    int minimumDistance(vector<int>& nums) {
    int sum=INT_MAX;
    int count=0;
    for(int i=0; i<nums.size();i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            for(int k=j+1;k<nums.size();k++)
            {
                if(nums[i]==nums[j] && nums[j]==nums[k] && nums[k]==nums[i])
                {
                    count=1;
                    int m=abs(i-j)+abs(j-k)+abs(k-i);
                    if(m<sum)
                    {
                        sum=m;
                    }
                }
            }
        }
    }
        if(nums.size()<3 || count==0)
        {
            return -1;
        }
        return sum;
    }
};