class Solution {
public:
    int solve(vector<int>& nums, int target, vector<int> & dp)
    {
        if(target==0)
        {
            return 1 ;
        }

        if(dp[target] !=-1)
        {
            return dp[target];
        }

        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=target)
            {
            maxi+=solve(nums,target-nums[i],dp);
            }
        }
        dp[target]=maxi;
     return dp[target];
    }


    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(target+1,-1);
       
        int ans= solve(nums,target,dp);
        //  if(target==0)
        // {
        //     return 0;
        // }
        return ans;
        
    }
};