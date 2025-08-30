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
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // for dp we are goig from bottom to up n-1 to 0 so declare vector of size n+1;
        dp[n][0]=dp[n][1]=0;
        
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                {
                    dp[i][buy]=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
                }else
                {
                    dp[i][buy]=max(prices[i]+dp[i+1][1],0+dp[i+1][0]);
                }
            }
        }
        // 1=buy and 0 is for sell 
        return dp[0][1];


    }
};