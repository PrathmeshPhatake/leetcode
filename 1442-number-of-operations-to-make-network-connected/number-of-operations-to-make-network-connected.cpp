class Solution {
public:
int unlti_parent(int node,vector<int>&parent)
{
    if(node==parent[node])return node;
    return parent[node]=unlti_parent(parent[node],parent);
}
void union_rank(int u,int v,vector<int>&parent,vector<int>&rank)
{
    int p_u=unlti_parent(u,parent);
    int p_v=unlti_parent(v,parent);
    if(p_u==p_v)return;
    if(rank[p_u]<rank[p_v])
    {
        parent[p_u]=p_v;
    }else if(rank[p_u]>rank[p_v])
    {
        parent[p_v]=p_u;
    }else
    { 
        parent[p_v]=p_u;
        rank[p_u]+=rank[p_v];
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
         vector<int>parent(n);
         vector<int>rank(n,0);
         if(connections.size()<n-1)  return -1;
         for(int i=0;i<n;i++)
         {
            parent[i]=i;
         }
         int count=0;
         sort(connections.begin(),connections.end());
         for(auto it:connections)
         {
            int u=it[0];
            int v=it[1];
             if(unlti_parent(u,parent)!=unlti_parent(v,parent))
             {
                union_rank(u,v,parent,rank);
             }
             
         }
         for(int i=0;i<n;i++)
         {
            if(parent[i]==i)
            {
                count++;
            }
         }
         return count-1;
    }
};