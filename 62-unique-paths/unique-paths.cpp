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
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            dp[i][0]=1;
        }
        for(int i=0;i<n;i++)
        {
            dp[0][i]=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=(dp[i-1][j]+dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};