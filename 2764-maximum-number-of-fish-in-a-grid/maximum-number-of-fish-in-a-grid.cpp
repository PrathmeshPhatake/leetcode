class Solution {
public:
int dfs(vector<vector<int>>&visited,vector<vector<int>>& grid,int r,int c)
{
     visited[r][c]=1;
    int n=grid.size();
    int m=grid[0].size();
    int count=0;
    count+=grid[r][c];
    int row[]={0,1,0,-1};
    int col[]={1,0,-1,0};
    for(int i=0;i<4;i++)
    {
        int  nr=r+row[i];
        int nc=c+col[i];
        if(nr>=0 && nc>=0 && nr<n && nc<m && visited[nr][nc]!=1 && grid[nr][nc]>0)
        {
           
            count+=dfs(visited,grid,nr,nc);            
        }
    }
    return count;
}
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=INT_MIN;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==0 && grid[i][j]>0)
                {
                  maxi=max(maxi,dfs(visited,grid,i,j));   
                }
            }
        }
        return maxi==INT_MIN?0:maxi;
    
    }
};