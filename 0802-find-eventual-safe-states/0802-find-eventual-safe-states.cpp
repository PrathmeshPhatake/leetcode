//safe node: a node not in cycle  it s
//return node not in cycle 
//time complexity:O(V+E)
//space compexity:0(V+E)
class Solution {
public:
  bool checkSafe(int node,vector<int>& visit,vector<int>& pathVisit,vector<vector<int>>& graph,vector<int>& checkNode)
  {
    visit[node]=1;
    pathVisit[node]=1;
    checkNode[node]=1;
    for(auto it:graph[node])
    {
        if(!visit[it])
        {
            if(checkSafe(it,visit,pathVisit,graph,checkNode)==true)
            {
                checkNode[node]=0;
                return true;
            }
        }
        else if(pathVisit[it])
        {
            checkNode[node]=0;
            return true;
        }
    }
    checkNode[node]=1;
    pathVisit[node]=0;
    return false;
  }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>visit(V,0);
        vector<int>pathVisit(V,0);
        vector<int>checkNode(V,0);
        vector<int>safeNode;
        
        //checknode 0=not  safe means in cycle  || 1= safest node 

        for(int i=0;i<V;i++)
        {
            if(visit[i]==0)
            {
                checkSafe(i,visit,pathVisit,graph,checkNode);
            }
        }
        for(int i=0;i<V;i++)
        {
            if(checkNode[i]==1)
            {
                safeNode.push_back(i);
            }
        }
        return safeNode;
    }
};