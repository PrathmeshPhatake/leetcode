class Solution {
public:
int func(int m,int n,int i,int j,vector<vector<int>>&dp)
{
    if(i==m-1 && j==n-1)
    {
        return 1;
    }
    if(i>=m || j>=n)
    {
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    // right
    return dp[i][j]=func(m,n,i,j+1,dp)+func(m,n,i+1,j,dp);
    
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(m,n,0,0,dp);
    }
};