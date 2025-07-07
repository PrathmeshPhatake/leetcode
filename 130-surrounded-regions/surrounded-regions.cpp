class Solution {
public:
void dfs(vector<vector<int>>&visited,vector<vector<char>>board,vector<vector<char>>&ans,int r,int c)
{
    int n=board.size();
    int m=board[0].size();
    visited[r][c]=1;
    ans[r][c]='O';
    int row[]={-1,0,1,0};
    int col[]={0,1,0,-1};
    for(int i=0;i<4;i++)
    {
        int nr=r+row[i];
        int nc=c+col[i];
        if(nr>=0 & nr<n && nc>=0 && nc<m && !visited[nr][nc] && board[nr][nc]=='O')
        {
            dfs(visited,board,ans,nr,nc);
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<char>>ans(n,vector<char>(m,'X'));
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            {
                dfs(visited,board,ans,i,0);
            }
             if(board[i][m-1]=='O')
            {
                dfs(visited,board,ans,i,m-1);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O')
            {
                dfs(visited,board,ans,0,i);
            }
             if(board[n-1][i]=='O')
            {
                dfs(visited,board,ans,n-1,i);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ans[i][j]=='X')
                {
                    board[i][j]='X';
                }
            }
        }
    }
};