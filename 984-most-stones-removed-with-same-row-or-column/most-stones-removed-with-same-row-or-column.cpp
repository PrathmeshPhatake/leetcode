// used dfs for it 
// one to other other to other
// number of path in graph
class Solution {
public:
 void dfs(vector<vector<int>>&stones ,int i,vector<int>&visited)
 {
    int n=stones.size();
    visited[i]=1;
    for(int j=0;j<n;j++)
    {
        if(!visited[j] && (stones[i][0]==stones[j][0] || stones[j][1]==stones[i][1]))
        {
            dfs(stones,j,visited);
        }
    }
 }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(stones,i,visited);
                count++;
            }
        }
        return n-count;
    }
};