class Solution {
private:
    int solve(vector<vector<int>>& grid, int i, int j, int empty) {
        // Base case
        if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] == -1) return 0;
        if (grid[i][j] == 2) return empty == 0 ? 1 : 0;  // Check if all empty cells are visited

        // Mark the cell as visited
        grid[i][j] = -1;
        empty--;

        // Explore the 4 possible directions
        int paths = solve(grid, i + 1, j, empty) + solve(grid, i - 1, j, empty) + solve(grid, i, j + 1, empty) + solve(grid, i, j - 1, empty);

        // Backtrack and unmark the cell as visited
        grid[i][j] = 0;
        empty++;
        
        return paths;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start_x = 0, start_y = 0, empty = 1; // Start with 1 for the starting square itself

        // Find the starting point and count the number of empty cells
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    start_x = i;
                    start_y = j;
                } else if (grid[i][j] == 0) {
                    empty++;
                }
            }
        }

        // Start the recursion from the start point
        return solve(grid, start_x, start_y, empty);
    }
};