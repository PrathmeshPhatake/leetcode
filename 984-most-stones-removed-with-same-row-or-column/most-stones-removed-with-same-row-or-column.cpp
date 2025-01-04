class Solution {
public:
void dfs(vector<int>&visited,int i,vector<vector<int>>& stones)
{
    int n=visited.size();
    visited[i]=1;
    for(int j=0;j<n;j++){
        if(!visited[j] && (stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1]))
        {
            dfs(visited,j,stones);
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
                dfs(visited,i,stones);
                count++;
            }
        }
        return n-count;
    }
};