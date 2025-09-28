class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0 ;i--){
            for(int j=0;j<=1;j++){
                for(int k=1;k<=2;k++)
                {
                    if(j){
                        dp[i][j][k]=max(dp[i+1][1][k],-prices[i]+dp[i+1][0][k]);
                    }else
                    {
                        dp[i][j][k]=max(dp[i+1][0][k],prices[i]+dp[i+1][1][k-1]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};