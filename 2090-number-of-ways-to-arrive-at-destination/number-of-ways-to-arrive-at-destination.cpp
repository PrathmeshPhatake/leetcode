#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        pq.push({0, 0});  // {distance, node}
        dist[0] = 0;
        ways[0] = 1;

        int mod = 1e9 + 7;

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto [neighbor, weight] : adj[node]) {
                long long newDist = d + weight;

                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    ways[neighbor] = ways[node];  // New shortest path found
                    pq.push({newDist, neighbor});
                } 
                else if (newDist == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % mod;  // Add ways
                }
            }
        }

        return ways[n - 1];  // Return count of shortest paths to node (n-1)
    }
};
