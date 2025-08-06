class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
            {
                dp[0][i]=i/coins[0];
            }else
            {
                dp[0][i]=INT_MAX;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                int ntake=0+dp[i-1][j];
                int take=INT_MAX;
                if(coins[i]<=j && dp[i][j-coins[i]]!=INT_MAX)
                {
                    take=1+dp[i][j-coins[i]];
                }
                dp[i][j]=min(take,ntake);
            }
        }
        return dp[n-1][amount]==INT_MAX?-1:dp[n-1][amount];

    }
};