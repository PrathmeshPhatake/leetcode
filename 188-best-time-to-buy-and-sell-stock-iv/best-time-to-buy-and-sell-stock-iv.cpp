class Solution {
public:
int func(vector<int> prices,vector<vector<vector<int>>>&dp,int i,int buy,int k,int x)
{
    int n=prices.size();
    if(i>=n || k>=x)
    {
        return 0;
    }
    if(dp[i][buy][k]!=-1) return dp[i][buy][k];
    if(buy){
        dp[i][buy][k]=max(-prices[i]+func(prices,dp,i+1,0,k,x),func(prices,dp,i+1,1,k,x));
    }else
    {
        dp[i][buy][k]=max(prices[i]+func(prices,dp,i+1,1,k+1,x),func(prices,dp,i+1,0,k,x));
    }
    return dp[i][buy][k];
}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k,-1)));
       return  func(prices,dp,0,1,0,k);

    }
};