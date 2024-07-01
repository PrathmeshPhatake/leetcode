class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>visit(n,vector<int>(m,0));
        int totalOne=0;
        int getOne=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    visit[i][j]=2;
                }
                if(grid[i][j]==1)
                {
                    totalOne++;
                }
            }

        }
        int tm=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(t,tm);
            
            for(int i=0;i<4;i++)
            {
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row>=0 && row<n && col>=0 && col<m && visit[row][col]!=2 && grid[row][col]==1)
                {
                     q.push({{row,col},t+1});
                     visit[row][col]=2;
                     getOne++;
                }
            }
        }
        if(getOne!=totalOne) return -1;


        return tm;
    }
};