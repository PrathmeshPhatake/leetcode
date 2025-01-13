class Solution {
public:
int func(vector<int>&prices,vector<vector<vector<int>>>&dp,int i,int buy,int cooldown)
{
    int n=prices.size();
    if(i>=n)
    {
        return 0;
    }
    if(dp[i][buy][cooldown]!=-1) return dp[i][buy][cooldown];
    if(buy)
    {
        int take=0;
        if(cooldown)
        {
            take=-prices[i]+func(prices,dp,i+1,0,1);
        }
        dp[i][buy][cooldown]=max(take,func(prices,dp,i+1,1,1));
    }
    else
    {
        dp[i][buy][cooldown]=max(prices[i]+func(prices,dp,i+1,1,0),func(prices,dp,i+1,0,1));
    }
    return dp[i][buy][cooldown];
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return func(prices,dp,0,1,1);
    }
};