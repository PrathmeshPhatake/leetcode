class Solution {
public:
bool dfs(vector<int>&color,int col,vector<vector<int>>&graph,int node)
{
     color[node]=col;
     for(auto neigh:graph[node])
     {
        if(color[neigh]==-1)
        {
            if(dfs(color,!col,graph,neigh)==false) return false;

        }
        else if(color[neigh]==col)
        {
            return false;
        }
     }
     return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>color(v,-1);
        for(int i=0;i<v;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(color,0,graph,i)==false)
                return false;
            }
        }
        return true;
    }
};