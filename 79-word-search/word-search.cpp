class Solution {
public:
    bool dfs(vector<vector<int>>& visited, vector<vector<char>>& board,
             string word, int r, int c, int index) {
        int n = board.size();
        int m = board[0].size();
        if (word.size() == index+1) {
            return true;
        }

        visited[r][c] = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                board[nrow][ncol] == word[index + 1] &&
                visited[nrow][ncol] != 1) {
                if (dfs(visited, board, word, nrow, ncol, index + 1))
                    return true;
            }
        }
        visited[r][c] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (word[0] == board[i][j])
                {
                    if (dfs(visited, board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};