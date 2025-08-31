class Solution {
public:
int func(vector<vector<int>>&dp,vector<int>prices,int i,int buy)
{
    int n=prices.size();
    if(i>=n)
    {
        return 0;
    }
    if(dp[i][buy]!=-1) return dp[i][buy];
    
    if(buy==1)
    {
        return dp[i][buy]=max(-prices[i]+func(dp,prices,i+1,0),0+func(dp,prices,i+1,1));
    }
    return dp[i][buy]=max(prices[i]+func(dp,prices,i+2,1),0+func(dp,prices,i+1,0));
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return  func(dp,prices,0,1);
    }
};