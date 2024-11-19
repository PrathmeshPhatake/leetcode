class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            if(obstacleGrid[i][0]==1) break;
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            if(obstacleGrid[0][i]==1) break;
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] != 1) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                if(obstacleGrid[i][j] == 1)
                {
                    dp[i][j]=0;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};