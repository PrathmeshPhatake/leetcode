class Solution {
public:
int func(int i,vector<int>& coins,int amount,vector<vector<int>>&dp)
{
    if(amount==0 )
    {
        return 0;
    }
    if(i<0)
    {
        return INT_MAX-1;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    int take=INT_MAX;
    if(coins[i]<=amount)
    {
        int sub=func(i,coins,amount-coins[i],dp);
        if(sub!=INT_MAX-1)
        {
            take=1+sub;
        }
    }
    int non_take=func(i-1,coins,amount,dp);
    return dp[i][amount]=min(take,non_take);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int value=func(n-1,coins,amount,dp);
        return value==INT_MAX-1?-1:value;
    }
};