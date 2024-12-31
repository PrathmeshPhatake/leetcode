class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
            
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>path(n,INT_MAX);
        q.push({0,{src,0}});
        path[src]=0;
        while(!q.empty())
        {
            auto [step,it]=q.front();
            int node=it.first;
            int dist=it.second;
            q.pop();
            if(step>k)continue;
            for(auto it:adj[node])
            {
                int nextnode=it.first;
                int nextdist=it.second;
                if(step<=k && path[nextnode]>dist+nextdist)
                {
                    path[nextnode]=dist+nextdist;
                    q.push({step+1,{nextnode,path[nextnode]}});
                }
            }
        }
        if(path[dst]==INT_MAX) return -1;
        return path[dst];
    }
};