class Solution {
public:
int func(vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp,int i,int j)
{
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    if(i==m-1 && j==n-1)
    return 1;
    if(i>m-1 || j>n-1 || obstacleGrid[i][j]==1)
    {return 0;}
    if(dp[i][j]!=-1) return dp[i][j];
    int left=0;
    int right=0;
    
        left=func(obstacleGrid,dp,i+1,j);
    
        right=func(obstacleGrid,dp,i,j+1);
    
    
    return dp[i][j]=right+left;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(obstacleGrid,dp,0,0);
    }
};