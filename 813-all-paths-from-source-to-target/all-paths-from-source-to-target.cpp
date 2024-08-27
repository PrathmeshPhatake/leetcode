class Solution {
public:
void path(vector<vector<int>>&graph,vector<vector<int>>&ans,vector<int>temp,int node)
{
    int n=graph.size();
    temp.push_back(node);
    if(node==n-1)
    {
        ans.push_back(temp);
        temp.clear();
        return ;
    }
    for(auto it:graph[node])
    {
        
        path(graph,ans,temp,it);
    }
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>temp;
        
        path(graph,ans,temp,0);
        return ans;
    }
};