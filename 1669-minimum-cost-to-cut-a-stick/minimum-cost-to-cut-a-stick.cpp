class Solution {
public:
int func(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
{
    if(i>j)return 0;
    int mini=INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k=i;k<=j;k++)
    {  
       int  cost=cuts[j+1]-cuts[i-1]+func(i,k-1,cuts,dp)+func(k+1,j,cuts,dp);
        mini=min(mini,cost);
    }
    return dp[i][j]=mini;
}
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int m=cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return func(1,m-2,cuts,dp);
    }
};