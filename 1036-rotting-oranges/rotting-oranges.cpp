class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]==2)
                {
                   visited[i][j]=1;
                   q.push({0,{i,j}});

                }
            }
        }
        while(!q.empty())
        {
            auto it=q.front();
            int r=it.second.first;
            int c=it.second.second;
            q.pop();
            count=max(count,it.first);

            int row[]={1,0,-1,0};
            int col[]={0,-1,0,1};
            for(int i=0;i<4;i++)
             {
             int nr=r+row[i];
             int nc=c+col[i];
             if(nr>=0 && nr<n && nc>=0 && nc<m && visited[nr][nc]!=1 && grid[nr][nc]==1)
             {
                visited[nr][nc]=1;
                q.push({count+1,{nr,nc}});
             } 
           }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {
                    return -1;
                }
            }
        }
        return count;
        
    }
};