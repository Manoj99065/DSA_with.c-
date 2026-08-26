class Solution {
public:
int solve(vector<int>& obstacles, int currlan, int currpos,vector<vector<int>>&dp)
{
    int n=obstacles.size()-1;
    if(currpos ==n)
    {
        return 0;
    }

    if(dp[currlan][currpos] != -1)
            return dp[currlan][currpos];

    // if(obstacles[currpos+1] != currlan)
    // {
    //     return solve(obstacles,currlan,currpos+1);
    // }
    if(obstacles[currpos+1] != currlan)
    {
        return solve(obstacles,currlan,currpos+1,dp);
    }

    else
    {  
        int ans=INT_MAX;
        for(int i=1;i<=3;i++)
        {
            if(currlan != i && obstacles[currpos]!=i)
            {
                ans=min(ans,1+solve(obstacles,i,currpos,dp));
            }
        }
        // return  ans;
        return dp[currlan][currpos]=ans;
    }
}
    int minSideJumps(vector<int>& obstacles) {
        // vector<vector<int>>dp(v)
        vector<vector<int>> dp(4,vector<int>(obstacles.size(), -1));
        return solve(obstacles,2,0,dp );
        
    }
};