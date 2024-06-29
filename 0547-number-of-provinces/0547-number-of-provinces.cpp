class Solution {
public:
//find adjecency node of this
   void dfs(int node,vector<vector<int>>&adjlist,vector<int>&vis)
   {
     vis[node]=1;
     for(auto it : adjlist[node])
     {
        if(!vis[it])
        {
            dfs(it,adjlist,vis);
        }
     }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int  n=isConnected.size();
        vector<vector<int>>adjlist(n);
        //matrix to list
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        int count=0;
        vector<int>vis(n,0);
        //it help to count different  value
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i,adjlist,vis);
            }

        }
        return count;
        
    }
};