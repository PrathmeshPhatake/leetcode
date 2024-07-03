class Solution {
public:
    bool bfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        queue<int> q;
        q.push(node);
        visited[node] = 0;  // Start coloring with color 0

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (auto neighbor : graph[current]) {
                if (visited[neighbor] == -1) {
                    // Color with opposite color
                    visited[neighbor] = !visited[current];
                    q.push(neighbor);
                } else if (visited[neighbor] == visited[current]) {
                    // If neighbor has the same color, graph is not bipartite
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> visited(v, -1);  // -1 means unvisited

        for (int i = 0; i < v; i++) {
            if (visited[i] == -1 && !graph[i].empty()) {
                if (!bfs(i, graph, visited)) {
                    return false;
                }
            }
        }

        return true;
    }
};