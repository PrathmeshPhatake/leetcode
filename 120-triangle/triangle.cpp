class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size()-1;
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),0));
        for(int i=0;i<=n;i++)
        {
            dp[n][i]=triangle[n][i];
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};