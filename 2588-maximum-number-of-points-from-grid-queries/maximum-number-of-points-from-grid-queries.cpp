class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(queries.size());
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) 
            sortedQueries.push_back({queries[i], i});
        
        sort(sortedQueries.begin(), sortedQueries.end());  // Sort queries in ascending order

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        int total = 0, idx = 0;
        int rowDir[] = {-1, 0, 1, 0};
        int colDir[] = {0, 1, 0, -1};

        while (idx < sortedQueries.size()) {
            int queryValue = sortedQueries[idx].first;
            int queryIndex = sortedQueries[idx].second;

            while (!pq.empty() && pq.top().first < queryValue) {
                auto [val, cell] = pq.top();
                pq.pop();
                total++;

                int r = cell.first, c = cell.second;
                for (int d = 0; d < 4; d++) {
                    int nr = r + rowDir[d], nc = c + colDir[d];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]) {
                        pq.push({grid[nr][nc], {nr, nc}});
                        visited[nr][nc] = true;
                    }
                }
            }
            ans[queryIndex] = total;  // Assign result for the current query
            idx++;
        }

        return ans;
    }
};
