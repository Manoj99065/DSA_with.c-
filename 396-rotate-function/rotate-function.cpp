// class Solution {
// public:
//     int maxRotateFunction(vector<int>& nums) {
//         int size=nums.size();
//         vector<int>ans(size*2);
//         for(int i=0;i<size*2;i++)
//             {
//             ans[i]=nums[i%size];
//             }
//             int i=0;
//         int ANS=0;
//         while(i<size)
//         {
//             int result=0;
//             for(int j=i;j<size+i;j++)
//             {
//                result+=ans[j]* (j - i);
//             }
//             ANS=max(ANS,result);
//             i++;
//         }
//         return ANS;  
//     }
// };

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        long long curr=0;
        for(int i=0 ;i<n;i++)
        {
            sum+=nums[i];
            curr+=1LL*i*nums[i];
        }

        long long ans=curr;
        for(int k=1;k<n;k++)
        {
            curr=curr+sum-1LL*n*nums[n-k];
            ans=max(ans,curr);
        }
        return ans;
    }
};