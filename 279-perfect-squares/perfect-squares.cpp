class Solution {
public:
     int solve(int n, vector<int>&dp)
     {
        if(n==0)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            // int mul=i*i;
           
               int maxi=1+solve(n-i*i,dp);
               ans=min(maxi,ans);
            
        }
        dp[n]=ans;
        return dp[n];
     }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        // if(n==1 || n==0)
        // {
        //     return n;
        // }


        return solve(n,dp);
        
        
    }
};