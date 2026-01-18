class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        if(grid[0][0]!=0)
        {
            return -1;
        }
        if(grid[n-1][m-1]!=0)
        {
            return -1;
        }
        visited[0][0]=1;
        int mini=INT_MAX;
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        int row[]={-1,-1,0,1,1,1,0,-1};
        int col[]={0,1,1,1,0,-1,-1,-1};
        while(!q.empty())
        {
            auto it=q.front();
            int dist=it.first;
            int r=it.second.first;
            int c=it.second.second;
            q.pop();
            if(r==n-1 && c==m-1){
                mini=min(mini,dist);
            }
            for(int i=0;i<8;i++)
            {
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && grid[nr][nc]==0)
                {
                    q.push({dist+1,{nr,nc}});
                    visited[nr][nc]=1;
                }
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};