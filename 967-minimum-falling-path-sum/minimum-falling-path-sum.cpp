class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix.size(),0));
        int m=matrix.size();
        int n=matrix[0].size();
        // base case 
        for(int i=0;i<n;i++)
        {
            dp[0][i]=matrix[0][i];
        }
        int mini=INT_MAX;
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int left=(j>0)?dp[i-1][j-1]:INT_MAX;
                int right=(j<n-1)?dp[i-1][j+1]:INT_MAX;
                int up=dp[i-1][j];
                dp[i][j]=matrix[i][j]+min({left,right,up});
              
            }

        }
        for(int i=0;i<n;i++)
        {
            mini=min(mini,dp[m-1][i]);
        }
        return mini;
    
    }
};