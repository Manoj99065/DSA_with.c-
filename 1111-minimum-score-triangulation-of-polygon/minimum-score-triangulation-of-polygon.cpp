class Solution {
public:
int solve(vector<int>&values,int i,int j,vector<vector<int>>&dp)
{
    if(j-i<2)
    {
        return 0;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++)
    {
      int left=solve(values,i,k,dp);
      int right=solve(values,k,j,dp);

       int triangle= values[i]*values[j]*values[k];

    //   ans=min(ans,left,right,tringle);
     ans = min(ans, left + right + triangle);
    
    }
    dp[i][j]=ans;
    return dp[i][j];
    // if(dp[i][j] != -1)
{
    return dp[i][j];
}
    // return ans;
}
    int minScoreTriangulation(vector<int>& values) {
    int size=values.size();
    // vector<int>dp(size,-1);
    vector<vector<int>> dp(size, vector<int>(size, -1));
    return solve(values,0,size-1,dp);
    
        
    }
};