//BFS TRAVERSAL
    //O(E) +O((K+1)*E);
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjlist(n);
        for (auto it : flights) {
            adjlist[it[0]].push_back({it[1], it[2]});
        }

        // (node, (current_cost, stops))
        queue<pair<int, pair<int, int>>> q;
        q.push({src, {0, 0}});
        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;
        
        while (!q.empty()) {
            int node = q.front().first;
            int cost = q.front().second.first;
            int stops = q.front().second.second;
            q.pop();

            if (stops > k) continue;

            for (auto it : adjlist[node]) {
                int nextNode = it.first;
                int nextCost = it.second;
                
                if (cost + nextCost < minCost[nextNode]) {
                    minCost[nextNode] = cost + nextCost;
                    q.push({nextNode, {minCost[nextNode], stops + 1}});
                }
            }
        }

        return minCost[dst] == INT_MAX ? -1: minCost[dst] ;
    }
};
