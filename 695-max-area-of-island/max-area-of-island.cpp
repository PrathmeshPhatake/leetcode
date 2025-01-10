class Solution {
public:
int dfs(vector<vector<int>>&grid,int r,int c,int m,int n)
{
    grid[r][c]=0;
    int count=1;
    int row[]={-1,0,1,0};
    int col[]={0,1,0,-1};
    for(int i=0;i<4;i++){
        int nr=r+row[i];
        int nc=c+col[i];
        if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1)
        {
            count+=dfs(grid,nr,nc,m,n);
        }
    }
    return count;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        int maxi=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    
                    maxi=max(maxi,dfs(grid,i,j,m,n));
                }
            }
        }
        return maxi;
    }
};