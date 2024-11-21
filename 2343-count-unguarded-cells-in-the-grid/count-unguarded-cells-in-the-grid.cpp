class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 2)); // Initialize all cells as unguarded (2)

        // Place guards (1) and walls (-1)
        for (auto& guard : guards)
            grid[guard[0]][guard[1]] = 1;
        for (auto& wall : walls)
            grid[wall[0]][wall[1]] = -1;

        // Sweep left-to-right and right-to-left
        for (int i = 0; i < m; i++) {
            bool guarded = false;
            for (int j = 0; j < n; j++) { // Left-to-right
                if (grid[i][j] == 1) guarded = true;
                else if (grid[i][j] == -1) guarded = false;
                else if (guarded) grid[i][j] = 0;
            }
            guarded = false;
            for (int j = n - 1; j >= 0; j--) { // Right-to-left
                if (grid[i][j] == 1) guarded = true;
                else if (grid[i][j] == -1) guarded = false;
                else if (guarded) grid[i][j] = 0;
            }
        }

        // Sweep top-to-bottom and bottom-to-top
        for (int j = 0; j < n; j++) {
            bool guarded = false;
            for (int i = 0; i < m; i++) { // Top-to-bottom
                if (grid[i][j] == 1) guarded = true;
                else if (grid[i][j] == -1) guarded = false;
                else if (guarded) grid[i][j] = 0;
            }
            guarded = false;
            for (int i = m - 1; i >= 0; i--) { // Bottom-to-top
                if (grid[i][j] == 1) guarded = true;
                else if (grid[i][j] == -1) guarded = false;
                else if (guarded) grid[i][j] = 0;
            }
        }

        // Count unguarded cells (still 2)
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    count++;
            }
        }
        return count;
    }
};
