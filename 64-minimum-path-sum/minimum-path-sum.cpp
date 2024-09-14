class Solution {
public:
int counting(vector<vector<int>>&dp,vector<vector<int>>&grid,vector<vector<int>>&visited,int row,int col)
{
    int m=grid.size();
    int n=grid[0].size();
    if(row==m-1 && col==n-1)
    {
        return  grid[row][col];
     
    }
    if(dp[row][col]!=-1) return dp[row][col];
    int drow[]={0,1};
    int dcol[]={1,0};
    int temp=INT_MAX;
    for(int i=0;i<2;i++)
    {
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow<m && ncol<n && visited[nrow][ncol]!=1)
        {
            visited[nrow][ncol]=1;
            temp=min(temp,counting(dp,grid,visited,nrow,ncol));
            visited[nrow][ncol]=0;
        }
    }
    return dp[row][col]=temp+grid[row][col];
    
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int tpath=INT_MAX;
        vector<vector<int>>visited(m,vector<int>(n,0));
        vector<vector<int>>dp(m,vector<int>(n,-1));
        visited[0][0]=1;
         return counting(dp,grid,visited,0,0);
        
    }
};