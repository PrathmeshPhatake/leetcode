class Solution {
public:
int ultimate_parent(vector<int>&parent,int node)
{
    if(node==parent[node])
    {
        return node;
    }
    return parent[node]=ultimate_parent(parent,parent[node]);
}

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        vector<int>parent(n,0);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(auto it:connections)
        {
            int ulu=ultimate_parent(parent,it[0]);
            int ulv=ultimate_parent(parent,it[1]);
            if(ulu==ulv)continue;
            if(rank[ulu]<rank[ulv])
            {
                parent[ulu]=ulv;
            }else if(rank[ulu]>rank[ulv])
            {
                parent[ulv]=ulu;
            }else
            {
                parent[ulu]=ulv;
                rank[ulv]++;
            }
        }
        int count=0;
        unordered_set<int>st;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
            {
                // count++;
                st.insert(i);
            }
        }
        return st.size()-1;
        
    }
};