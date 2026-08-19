class Solution {
public:

    int solve(vector<int>&coins, vector<int>&dp,int amount)
    {
        if(amount==0)
        {
            return 0;
        }

        if(dp[amount] != -1)
        {
            return dp[amount];
        }

        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            if(coins[i]<=amount)
            {
            int ans=solve(coins,dp,amount-coins[i]);
            if(ans != INT_MAX)
            {
                 mini=min(mini,ans+1);
            }
            }
        }
        dp[amount]=mini;
        return dp[amount];
            
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans=solve(coins,dp,amount);
        if(ans== INT_MAX)
        {
            return -1;
        }
        return ans;
        
        
    }
};