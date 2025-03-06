class Solution {
public:
int func(vector<int>&coins,int amount,int i,vector<vector<int>>&dp)
{
    if(amount==0) return 0;
    if(i<0) return INT_MAX-1;
    if(dp[i][amount]!=-1)return dp[i][amount];
    int take=INT_MAX; 
    if(amount>=coins[i])
    {
        int subres=func(coins,amount-coins[i],i,dp);
       if(subres!=INT_MAX)
       {
          take=1+subres;
       }
    }
    int nontake=0+func(coins,amount,i-1,dp);
    return dp[i][amount]=min(take,nontake);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int result= func(coins,amount,coins.size()-1,dp);
        return result==INT_MAX-1?-1:result;
    }
};