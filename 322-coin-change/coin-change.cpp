class Solution {
    int func(vector<vector<int>>&dp,vector<int>&coins,int amount,int i)
    {
       if(amount==0)return 0;
       if(amount<0|| i<0)return INT_MAX-1;
       if(dp[i][amount]!=-1) return dp[i][amount];
       int take=1+func(dp,coins,amount-coins[i],i);
       int non_take=func(dp,coins,amount,i-1);
       return dp[i][amount]=min(take,non_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=func(dp,coins,amount,n-1);
        return (ans<INT_MAX-1)?ans:-1;
    }
};