class Solution {
public:
    int count=0;
    void solve(vector<vector<char>> &board,int sr,int sc,char ch){
        if(sr>=board.size() || sc>= board[0].size() || sr<0 || sc<0 || board[sr][sc]=='B')    
            return;
        if(board[sr][sc]=='p'){
            count++;
            return;
        }
        if(board[sr][sc]=='.'){
            if(ch=='u') solve(board,sr-1,sc,'u');
            if(ch=='d') solve(board,sr+1,sc,'d');
            if(ch=='l') solve(board,sr,sc-1,'l');
            if(ch=='r') solve(board,sr,sc+1,'r');
        }
        
    }
    int numRookCaptures(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='R'){ 
                    solve(board,i-1,j,'u');
                    solve(board,i+1,j,'d');
                    solve(board,i,j-1,'l');
                    solve(board,i,j+1,'r');
                    break;
                }
            }
        return count;
    }
};