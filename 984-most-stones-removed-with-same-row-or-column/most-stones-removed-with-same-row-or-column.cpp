class Solution {
public:
int ulti_parent(int node,vector<int>&parent){
    if(parent[node]==node)
    {
        return node;
    }
    return parent[node]=ulti_parent(parent[node],parent);
}
void union_rank(int u,int v,vector<int>&parent,vector<int>&rank)
{
    int ul_u=ulti_parent(u,parent);
    int ul_v=ulti_parent(v,parent);
    if(ul_u==ul_v)return;
    if(rank[ul_u]<rank[ul_v])
    {
        parent[ul_u]=parent[ul_v];
    }
    else if(rank[ul_v]<rank[ul_u])
    {
        parent[ul_v]=parent[ul_u];
    }else
    {
        parent[ul_v]=parent[ul_u];
        rank[ul_u]=parent[ul_v];
    }
}
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=INT_MIN;
        int maxcol=INT_MIN;
        for(auto it:stones)
        {
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        vector<int>parent(maxrow+maxcol+2);
        vector<int>rank(maxrow+maxcol+2,0);
        for(int i=0;i<parent.size();i++)
        {
            parent[i]=i;
        }
        
        unordered_map<int, int> stoneNodes;
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxrow + 1;
            union_rank(nodeRow, nodeCol,parent,rank);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int count=0;
        for(auto it:stoneNodes)
        {
            if(parent[it.first]==it.first)
            {
                count++;
            }
        }
        return n-count;
        
    }
};