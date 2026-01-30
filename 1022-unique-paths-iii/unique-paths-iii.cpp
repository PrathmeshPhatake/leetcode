class Solution {
public:
    int func(vector<vector<int>>&grid, int r, int c, int empty) {
        int n = grid.size();
        int m = grid[0].size();
        if (r >= n || c >= m || r < 0 || c < 0 || grid[r][c] == -1)
            return 0;
        if (grid[r][c] == 2)
            return empty == 0 ? 1 : 0;
        grid[r][c] = -1;
        empty--;

        int path = func(grid, r-1, c, empty)+func(grid, r, c+1, empty)+func(grid, r+1, c, empty)+func(grid, r, c-1, empty);
        grid[r][c]=0;
        empty++;
        return path;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start = 0;
        int end = 0;
        int empty = 1;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    start = i;
                    end = j;
                } else if (grid[i][j] == 0) {
                    empty++;
                }
            }
        }
        return func(grid, start, end, empty);
    }
};