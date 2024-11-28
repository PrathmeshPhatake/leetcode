class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int mini=INT_MAX;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>qp;
        vector<vector<int>>visited(m,vector<int>(n,-1));
        qp.push({0,{0,0}});
        visited[0][0]=1;
        while(!qp.empty()){
            int count=qp.top().first;
            int r=qp.top().second.first;
            int c=qp.top().second.second;
            qp.pop();
            if(r==m-1 && c==n-1)
            {
                mini=min(mini,count);
            }
            int row[]={-1,0,1,0};
            int col[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int n_r=r+row[i];
                int n_c=c+col[i];
                if(n_r>=0 && n_c>=0 && n_r<m && n_c<n && visited[n_r][n_c]==-1)
                {
                    visited[n_r][n_c]=1;
                    if(grid[n_r][n_c]==1)
                    {
                        qp.push({count+1,{n_r,n_c}});
                    }
                    else
                    {
                        qp.push({count,{n_r,n_c}});
                    }
                }
            }
        }
        return mini;
        
    }
};