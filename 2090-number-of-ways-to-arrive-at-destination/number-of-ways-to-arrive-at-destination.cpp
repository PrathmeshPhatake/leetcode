class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int modulo=1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        vector<long long> path(n, LLONG_MAX);
        vector<int> ways(n, 0); // to count the number of ways to reach each node
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        q.push({0, 0});
        path[0] = 0;
        ways[0] = 1; // Only one way to reach the source node
        
        while (!q.empty()) {
            auto [dist, node] = q.top();
            q.pop();
            
            if (dist > path[node]) continue; // Skip if we've already found a shorter path
            
            for (auto it : adj[node]) {
                int nextnode = it.first;
                int nextdist = it.second;
                
                if (path[nextnode] > dist + nextdist) {
                    path[nextnode] = dist + nextdist;
                    ways[nextnode] = ways[node];
                    q.push({path[nextnode], nextnode});
                } else if (path[nextnode] == dist + nextdist) {
                    ways[nextnode] = (ways[nextnode]+ways[node])%modulo;
                }
            }
        }
        
        return ways[n - 1] == 0 ? -1 : ways[n - 1]; // If there are no paths to the last node, return -1
    }
};
