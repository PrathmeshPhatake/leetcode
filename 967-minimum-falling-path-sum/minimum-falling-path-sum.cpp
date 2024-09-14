class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int temp=INT_MAX;
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j-1>=0)
                {
                    dp[i][j]=min(dp[i][j],matrix[i][j]+dp[i-1][j-1]);
                }
                dp[i][j]=min(dp[i][j],matrix[i][j]+dp[i-1][j]);
                if(j+1<n)
                {
                    dp[i][j]=min(dp[i][j],matrix[i][j]+dp[i-1][j+1]);
                }
            }
        }
        return *min_element(dp[m-1].begin(),dp[m-1].end());
        
    }
};