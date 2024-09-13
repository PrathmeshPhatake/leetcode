class Solution {
public:
int counting(vector<vector<int>>&visited,vector<vector<int>>&dp,int m,int n,int row,int col,int& count)
{
    if(row>=m-1 && col>=n-1)
    {
        if(row==m-1 && col==n-1)
        {
            return 1;
        }
        return 0;
    }
    // move only in right and down
    if(dp[row][col]!=-1) return dp[row][col];
    int drow[]={0,1};
    int dcol[]={1,0};
    int temp=0;
    for(int i=0;i<2;i++)
    {
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && visited[nrow][ncol]==0)
        {
            visited[nrow][ncol]=1;
            temp+=counting(visited,dp,m,n,nrow,ncol,count);
            visited[nrow][ncol]=0;
        }
    }
    return dp[row][col]=temp;
}
    int uniquePaths(int m, int n) {
        int count=0;
        vector<vector<int>>visited(m,vector<int>(n,0));
        vector<vector<int>>dp(m,vector<int>(n,-1));
        visited[0][0]=1;
        return counting(visited,dp,m,n,0,0,count);
    }
};
