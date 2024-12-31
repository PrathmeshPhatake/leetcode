class Solution {
public:
bool dfs(vector<vector<int>>&graph,vector<int>&visited,int node)
{
    if(visited[node]!=0)
    {
        return visited[node]==2;
    }
    visited[node]=1;
    for(auto neigh:graph[node])
    {
        if(!dfs(graph,visited,neigh))
        {
            return false;
        }
    }
    visited[node]=2;
    return true;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>visited(V,0);  // 0=for unvisit,1=visit 2=safe we want safe node
        vector<int>result;
        for(int i=0;i<V;i++)
        {
            if(dfs(graph,visited,i))
            {
                result.push_back(i);
            }
        }
        return result;
    }
};