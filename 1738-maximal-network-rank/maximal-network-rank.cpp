class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>>connected(n,vector<bool>(n,false));
        vector<int>degree(n,0);
        for(auto it:roads)
        {
            int u=it[0];
            int v=it[1];
            degree[u]++;
            degree[v]++;
            connected[u][v]=connected[v][u]=true;
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int rank=degree[i]+degree[j];
                if(connected[i][j])rank--;
                maxi=max(maxi,rank);
            }
        }
        return maxi;
        
    }
};