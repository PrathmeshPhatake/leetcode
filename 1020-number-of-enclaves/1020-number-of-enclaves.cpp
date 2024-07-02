//TIME COMPLEXITY :BORDER(2M+2N) + BFS(M*N*4) + FIND MIDLE
class Solution {
private:
    void bfs(int r, int c, vector<vector<int>>& visit, vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        visit[r][c] = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int row = r + drow[i];
            int col = c + dcol[i];
            if (row>=0 && row<n && col>=0 && col<m && grid[row][col] == 1 && visit[row][col] != 1) {
                bfs(row, col, visit, grid);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visit(n, vector<int>(m, 0));
        int count = 0;
        // for row
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && visit[i][0] == 0) {
                bfs(i, 0, visit, grid);
            }
            if (grid[i][m - 1] == 1 && visit[i][m - 1] == 0) {
                bfs(i, m - 1, visit, grid);
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && visit[0][i] == 0) {
                bfs(0, i, visit, grid);
            }
            if (grid[n- 1][i] == 1 && visit[n - 1][i] == 0) {
                bfs(n - 1, i, visit, grid);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visit[i][j] == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};