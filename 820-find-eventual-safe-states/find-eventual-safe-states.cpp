class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // we want reverse graph for that 
        int numCourses=graph.size();
        int n=graph.size();
       
        vector<vector<int>>revgraph(n);
        vector<int> indegree(n, 0);
        for(int u=0;u<n;u++)
        {
            for(auto v:graph[u])
            {
                revgraph[v].push_back(u);
                indegree[u]++; 
            }
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if(indegree[i]==0)
            {
            q.push(i);
            }
        }
        vector<int>ans;
        while (!q.empty()) {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:revgraph[node])
            {
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};