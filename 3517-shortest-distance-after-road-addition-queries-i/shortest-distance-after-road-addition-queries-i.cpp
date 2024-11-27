class Solution {
public:
int  disjikstra(int s,int V,vector<vector<pair<int,int>>>&graph)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(V,INT_MAX);
    pq.emplace(0,s);
    dist[s]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        int distance=pq.top().first;
        pq.pop();
        //find the nearest distnace at node
        for(auto it:graph[u])
        {
            int v=it.first;
            int weight=it.second;
            // if(distance+weight>=dist[v])continue;
            if(distance+weight<dist[v])
            {
                dist[v]=distance+weight;
                pq.emplace(dist[v],v); 
            }
        }
    }
    return dist[V-1];
}
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pair<int,int>>>graph(n);
        vector<int>ans(queries.size());
        for(int i=0;i<n-1;i++)
        {
            graph[i].push_back({i+1,1});
        }
        for(int i=0;i<queries.size();i++)
        {
            auto it=queries[i];
            graph[it[0]].emplace_back(it[1],1);
            int path=disjikstra(0,n,graph);
            ans[i]=path;
        }
        return ans;
    }
};