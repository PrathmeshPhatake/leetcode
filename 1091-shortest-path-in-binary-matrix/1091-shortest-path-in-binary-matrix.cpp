
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0 || grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        dist[0][0] = 1;

        int drow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dcol[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n-1 && c == n-1) {
                return dis;
            }

            for (int i = 0; i < 8; i++) {
                int row = r + drow[i];
                int col = c + dcol[i];
                if (row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 0 && dis + 1 < dist[row][col]) {
                    dist[row][col] = dis + 1;
                    q.push({dis + 1, {row, col}});
                }
            }
        }
        return -1;
    }
};