class Solution {
public:
    bool func(vector<vector<char>>& board, string word, int index,int r,int c) {
        if(index==word.size()) return true;
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]!=word[index])
        {
            return  false;
        }
        char temp=board[r][c];
        board[r][c]='#';
        bool found=func(board,word,index+1,r+1,c)|| func(board,word,index+1,r,c+1)||func(board,word,index+1,r-1,c)||func(board,word,index+1,r,c-1);
        board[r][c]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if(func(board,word,0,i,j))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};