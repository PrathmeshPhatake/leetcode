class Solution {
public:
    int counting(vector<vector<int>>& dp, vector<vector<int>>& visited,vector<vector<int>>& obstacleGrid,int row, int col) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if (row >=m-1 && col >= n-1) {
            if (row == m - 1 && col == n - 1) {
                return 1;
            }
            return 0;
        }
        if(dp[row][col]!=-1)return dp[row][col];
        // right down
        int drow[]={0,1};
        int dcol[]={1,0};
        int temp=0;
        for(int i=0;i<2;i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && visited[nrow][ncol]!=1 && obstacleGrid[nrow][ncol]!=1)
            {
                visited[nrow][ncol]=1;
                temp+=counting(dp,visited,obstacleGrid,nrow,ncol);
                visited[nrow][ncol]=0;
            }
        }
        return dp[row][col]=temp;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        vector<vector<int>>visited(m,vector<int>(n,0));
        visited[0][0]=1;
        if(obstacleGrid[0][0]==1)return 0;
        return counting(dp,visited,obstacleGrid,0,0);
        
    }
};