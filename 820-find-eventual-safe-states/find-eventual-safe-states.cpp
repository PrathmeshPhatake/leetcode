class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>indegre(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                adj[it].push_back(i);
                indegre[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegre[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node])
            {
                indegre[it]--;
                if(indegre[it]==0)q.push(it);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;

    }
};