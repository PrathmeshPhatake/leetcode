class Solution {
private:
    // Function to perform Depth First Search (DFS)
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col) {
        vis[row][col] = 1;
        int m = vis.size();
        int n = vis[0].size();
        queue<pair<int,int>> q;
        q.push({row, col});
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            // Check if the cell is within the bounds of the grid
            if (r >= 0 && r < m && c >= 0 && c < n) {
                // Check neighboring cells
                if (r > 0 && grid[r - 1][c] == '1' && !vis[r - 1][c]) {
                    q.push({r - 1, c});
                    vis[r - 1][c] = 1;
                }
                if (r < m - 1 && grid[r + 1][c] == '1' && !vis[r + 1][c]) {
                    q.push({r + 1, c});
                    vis[r + 1][c] = 1;
                }
                if (c > 0 && grid[r][c - 1] == '1' && !vis[r][c - 1]) {
                    q.push({r, c - 1});
                    vis[r][c - 1] = 1;
                }
                if (c < n - 1 && grid[r][c + 1] == '1' && !vis[r][c + 1]) {
                    q.push({r, c + 1});
                    vis[r][c + 1] = 1;
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0) return 0; // Empty grid
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        int cnt = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
};
