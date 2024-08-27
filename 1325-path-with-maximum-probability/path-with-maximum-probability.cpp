class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        vector<vector<pair<int, double>>> adjlist(n);
        

        for (int i = 0; i < succProb.size(); i++) {
            adjlist[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adjlist[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        //    {dist,node}
        vector<double> dist(n, 0);
        priority_queue<pair<double, int>>pq;

        pq.push({1.0, start_node});

        dist[start_node] = 1.0;
        vector<int>visit(n,0);
        
        while (!pq.empty()) {
            int node = pq.top().second;
            double distance = pq.top().first;
            pq.pop();
            if(visit[node]==1) continue;
            visit[node]=1;


            for (auto it : adjlist[node]) {
                int newnode = it.first;
                double newDist = it.second;
                if (distance * newDist > dist[newnode] ) {
                    dist[newnode] = distance * newDist;
                   
                    pq.push({dist[newnode], newnode});
                }
            }
        }
        return dist[end_node];
    }
};