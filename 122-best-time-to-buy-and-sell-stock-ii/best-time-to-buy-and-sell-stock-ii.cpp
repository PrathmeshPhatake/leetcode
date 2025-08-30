class Solution {
public:
int func( vector<vector<int>>&dp,vector<int>&prices,int i,int profit,int buy)
{
    int n=prices.size();
    if(i==n)
    {
        return 0;

    }
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy)
    {
        profit=max(-prices[i]+func(dp,prices,i+1,profit,0),0+func(dp,prices,i+1,profit,1));

    }else
    {
                profit=max(prices[i]+func(dp,prices,i+1,profit,1),0+func(dp,prices,i+1,profit,0));
    }
    return dp[i][buy]=profit;

}
    int maxProfit(vector<int>& prices) {
        int profit=INT_MIN;
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return func(dp,prices,0,profit,1);

    }
};