class Solution {
public:
void dfs(vector<vector<char>>&visited,vector<vector<char>>board,int r,int c)
{
    int n=visited.size();
    int m=visited[0].size();
    visited[r][c]='O';
    int row[]={0,1,0,-1};
    int col[]={1,0,-1,0};
    for(int i=0;i<4;i++)
    {
        int nr=r+row[i];
        int nc=c+col[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && visited[nr][nc]=='X' && board[nr][nc]=='O')
        {
            dfs(visited,board,nr,nc);
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<char>>visited(n,vector<char>(m,'X'));
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' && visited[i][0]=='X')
            {
                dfs(visited,board,i,0);
            }
            if(board[i][m-1]=='O' && visited[i][m-1]=='X')
            {
                dfs(visited,board,i,m-1);
            }
        }
         for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O' && visited[0][i]=='X')
            {
                dfs(visited,board,0,i);
            }
            if(board[n-1][i]=='O' && visited[n-1][i]=='X')
            {
                dfs(visited,board,n-1,i);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 if(visited[i][j]=='X')
                 {
                    board[i][j]='X';
                 }
            }
        }
    }
};