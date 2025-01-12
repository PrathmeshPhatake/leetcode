class Solution {
public:
int func(vector<int>&prices,int i,int buy,int k,vector<vector<vector<int>>>&dp)
{
    int n=prices.size();
    if(i>=n || k>=2)
    {
        return 0;
    }
    if(dp[i][buy][k]!=-1)return dp[i][buy][k];
    if(buy)
    {
        dp[i][buy][k]=max(-prices[i]+func(prices,i+1,0,k,dp),func(prices,i+1,1,k,dp));
    }
    else
    {
        dp[i][buy][k]=max(prices[i]+func(prices,i+1,1,k+1,dp),func(prices,i+1,0,k,dp));
    }
    return dp[i][buy][k];
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return func(prices,0,1,0,dp);
    }
};