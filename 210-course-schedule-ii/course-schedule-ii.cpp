class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>ans;
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indegree(numCourses,0);
        for(auto it:prerequisites)
        {
            indegree[it[0]]++;
        } 
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if( indegree[it]==0) q.push(it);
            }
        }
        if(ans.size()!=numCourses)  return {};
        return ans;
    }
};