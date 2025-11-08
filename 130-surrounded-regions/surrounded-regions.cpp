class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<char>>temp(n,vector<char>(m,'X'));
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            {
                q.push({i,0});
                visited[i][0]=1;
            }
             if(board[i][m-1]=='O')
            {
                q.push({i,m-1});
                visited[i][m-1]=1;

            }
        }
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O')
            {
                q.push({0,i});
                visited[0][i]=1;

            }
             if(board[n-1][i]=='O')
            {
                q.push({n-1,i});
                visited[n-1][i]=1;

            }
        }
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            temp[r][c]='O';
            for(int i=0;i<4;i++)
            {
                int nr=r+row[i];
                int nc=c+col[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]=='O' && !visited[nr][nc])
                {
                    q.push({nr,nc});
                    visited[nr][nc]=1;
                }
            }
        }
        board=temp;
    }
};