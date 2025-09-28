class Solution {
public:
int func(vector<vector<int>>&dp,int i,vector<int>&prices,int buy,int profit)
{
    int n=prices.size();
    if(i==n)
    {
        return 0;
    }
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy)
    {
        dp[i][buy]=max(-prices[i]+func(dp,i+1,prices,0,profit),0+func(dp,i+1,prices,1,profit));
    }else
    {
        dp[i][buy]=max(prices[i]+func(dp,i+1,prices,1,profit),0+func(dp,i+1,prices,0,profit));

    }
    return dp[i][buy];

}
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return func(dp,0,prices,1,profit);
    }
};