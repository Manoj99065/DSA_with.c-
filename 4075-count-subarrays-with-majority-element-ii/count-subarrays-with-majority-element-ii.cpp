// class Solution {
// public:
//     long long countMajoritySubarrays(vector<int>& nums, int target) {
//         int n=nums.size();
//         int i=0;
//         int j=0;
//         int count=0;
//         int cnt=0;
//         while(j<n)
//         {
          
//           if(i<n)
//           {
//             if(nums[i]==target)
//             {
//                 cnt++;
//             }
//             int len=i-j+1;
//             len=len/2;
//             if(cnt>len)count++;
//             i++;
//           }  
//           else
//           {
//             cnt=0;
//             j++;
//             i=j;
//           }
//         }
//        return count; 
//     }
// };




class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
      unordered_map<int ,int>mp;
      long long  left=0;
       int count=0;
      mp[0]=1;
      long long result=0;
      for(int i=0;i<nums.size();i++)
      {
        if(nums[i]==target)
        {
          left+=mp[count];
          count++;
        }
        else
        {
            count--;
            left-=mp[count];
        }
        mp[count]+=1;
        result+=left;
      }
      return result;
    }
};