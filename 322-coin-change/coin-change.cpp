class Solution {
public:
int memoization(vector<vector<int>>&dp,vector<int>&coins,int index,int amount)
{
    if(amount==0) return 0;
    if(index<0 || amount<0) return INT_MAX-1;
    if(dp[index][amount]!=-1) return dp[index][amount];
    int res=INT_MAX;
    if(coins[index]>amount) 
    {
        int Non_taken=0+memoization(dp,coins,index-1,amount);
        res=Non_taken;
    }
    else
    {
        int Non_taken=0+memoization(dp,coins,index-1,amount);
        int taken=1+memoization(dp,coins,index,amount-coins[index]);
        res=min(Non_taken,taken);
    }
    return dp[index][amount]=res;
    
}
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int res=memoization(dp,coins,coins.size()-1,amount);
        return res==INT_MAX-1? -1:res;
    }
};