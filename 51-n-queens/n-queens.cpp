class Solution {
public:
bool isSafe(vector<vector<char>>&board,int r,int c,int n)
{
    for(int i=0;i<c;i++)
    {
        if(board[r][i]=='Q')
        {
            return false;
        }
    }
    for(int i=r,j=c;i>=0 && j>=0 ;i--,j--)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    for(int i=r,j=c;i<n && j>=0;i++,j--)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    return true;
}
void func(vector<vector<string>>&ans,vector<vector<char>>&board,int c,int n){
    if(c==n)
    {
        vector<string>temp;
        for(int i=0;i<n;i++)
        {
            string row(board[i].begin(),board[i].end());
            temp.push_back(row);
        }
        ans.push_back(temp);
    }
    for(int i=0;i<n;i++)
    {
        if(isSafe(board,i,c,n))
        {
            board[i][c]='Q';
            func(ans,board,c+1,n);
            board[i][c]='.';
        }
    }    
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<char>>board(n,vector<char>(n,'.'));
        func(ans,board,0,n);
        return ans;
    }
};