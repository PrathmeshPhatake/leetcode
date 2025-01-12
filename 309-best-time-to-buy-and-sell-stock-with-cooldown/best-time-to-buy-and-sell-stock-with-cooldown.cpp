class Solution {
public:
int func(vector<int>&prices,int i,int buy,int neutrilized,vector<vector<vector<int>>>&dp)
{
    int n=prices.size();
    if(i>=n)return 0;
    if(dp[i][buy][neutrilized]!=-1)return dp[i][buy][neutrilized];
    if(buy){
        int take=0;
        if(neutrilized==0)
        {
            take=-prices[i]+func(prices,i+1,0,0,dp);
        }
        dp[i][buy][neutrilized]=max(take,func(prices,i+1,1,0,dp));
    }
    else
    {
        dp[i][buy][neutrilized]=max(prices[i]+func(prices,i+1,1,1,dp),func(prices,i+1,0,0,dp));
    }
    return dp[i][buy][neutrilized];

}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return func(prices,0,1,0,dp);
    }
};