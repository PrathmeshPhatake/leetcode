class Solution {
public:
void dfs(vector<vector<int>>&grid,int r,int c)
{
    int n=grid.size();
    int m=grid[0].size();
    grid[r][c]=-1;
    int row[]={0,1,0,-1};
    int col[]={1,0,-1,0};
    for(int i=0;i<4;i++)
    {
        int nr=r+row[i];
        int nc=c+col[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m  && grid[nr][nc]==1)
        {
            dfs(grid,nr,nc);
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
            {
                dfs(grid,i,0);
                
            }

            if(grid[i][m-1]==1 )
            {
                dfs(grid,i,m-1);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1 )
            {
                dfs(grid,0,i);
                
            }

            if(grid[n-1][i]==1 )
            {
                dfs(grid,n-1,i);
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if( grid[i][j]==1)
                count++;
            }
        }
        return count;
    }
};