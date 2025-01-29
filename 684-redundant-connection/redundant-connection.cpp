class Solution {
public:
int ulti_parent(int u,vector<int>&parent)
{
    if(parent[u]==u)
    {
        return u;
    }
    return parent[u]=ulti_parent(parent[u],parent);
}
bool union_rank(int u,int v,vector<int>&parent,vector<int>&rank)
{
    int ul_u=ulti_parent(u,parent);
        int ul_v=ulti_parent(v,parent);
        if(ul_u==ul_v)return false;
        if(rank[ul_u]>rank[ul_v])
        {
            parent[ul_v]=ul_u;
        }
        else if(rank[ul_u]<rank[ul_v])
        {
            parent[ul_u]=ul_v;
        }
        else
        {
            parent[ul_u]=ul_v;
            rank[ul_v]++;
        }
        return true;
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1,0);
        vector<int>rank(n+1,0);
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
        for(auto it:edges)
        {
            if(!union_rank(it[0],it[1],parent,rank))
            {
                ans.push_back(it[0]);
                ans.push_back(it[1]);
            }
        }
        return ans;
    }
};