class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[0][1]=INT_MIN;
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int b=0;b<=1;b++)
            {
                if(b)
                {
                    dp[i][b]=max(dp[i-1][1],-prices[i-1]+dp[i-1][0]);
                }else
                {
                    dp[i][b]=max(dp[i-1][0],prices[i-1]+dp[i-1][1]);
                }
            }
        }
        return dp[n][0];
    }
};