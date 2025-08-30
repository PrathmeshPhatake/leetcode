class Solution {
public:
int func( vector<vector<vector<int>>>&dp,vector<int>prices,int i,int& profit,int cap,int buy)
{
    int n=prices.size(); 
    if(i==n) return 0;
    if(cap==0) return 0;
    if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
    if(buy)
    {
        dp[i][buy][cap]=max(-prices[i]+func(dp,prices,i+1,profit,cap,0),0+func(dp,prices,i+1,profit,cap,1));
    }else
    {
        dp[i][buy][cap]=max(prices[i]+func(dp,prices,i+1,profit,cap-1,1),0+func(dp,prices,i+1,profit,cap,0));
    }
    return dp[i][buy][cap];
}
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        // return func(dp,prices,0,profit,2,1);
        // first base case cap is 0 then it can be any thing  but value of dp is 0 
        for(int i=n-1;i>=0;i--)
        {
            for(int b=0;b<=1;b++)
            {
                for(int c=1;c<=2;c++)
                {
                    if(b)
                    {
                        dp[i][b][c]=max(-prices[i]+dp[i+1][0][c],dp[i+1][1][c]);
                    }else
                    {
                        dp[i][b][c]=max(prices[i]+dp[i+1][1][c-1],dp[i+1][0][c]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};