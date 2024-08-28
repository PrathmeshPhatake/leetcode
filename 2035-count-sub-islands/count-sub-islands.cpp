class Solution {
public:
    bool bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c, int mark) {
        int n = grid1.size();
        int m = grid1[0].size();
        
        // If grid1 at the current position is not 1, this can't be a sub-island
        if (grid1[r][c] != 1) return false;
        
        bool flag = true;
        grid2[r][c] = mark;
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid2[nrow][ncol] == 1) {
                // If the adjacent cell in grid1 is not 1, then it can't be a sub-island
                if (grid1[nrow][ncol] != 1) flag = false;
                
                // Recurse to check the neighboring cells
                if (!bfs(grid1, grid2, nrow, ncol, mark)) flag = false;
            }
        }
        
        return flag;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int cnt = 0;
        int mark = 2;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1) {
                    // Check if the island in grid2 is a sub-island of grid1
                    if (bfs(grid1, grid2, i, j, mark++)) {
                        cnt++;
                    }
                }
            }
        }
        
        return cnt;
    }
};