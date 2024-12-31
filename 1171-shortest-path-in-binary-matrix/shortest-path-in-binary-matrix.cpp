class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({1,{0,0}});
        grid[0][0]=1;
        while(!pq.empty())
        {
           auto [step,rc]=pq.top();
           int r=rc.first;
           int c=rc.second;
           pq.pop();
           if(r==m-1 && c==n-1)
           {
             return step;
           }
           int row[]={0,1,1,1,0,-1,-1,-1};
           int col[]={1,1,0,-1,-1,-1,0,1};
           for(int i=0;i<8;i++)
           {
              int nr=r+row[i];
              int nc=c+col[i];
              if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==0)
              {
                pq.push({step+1,{nr,nc}});
                grid[nr][nc]=1;
              }
           }
        }
        return -1;
    }
};