class Solution {
    int func(vector<int>&coins,vector<vector<int>>&dp,int amount,int i)
    {
        int n=coins.size();
        if(amount==0)
        {
            return 1;

        }
        if(i>=n)return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take_k=0;
        int take_s=0;
        int skip=0;
        if(coins[i]<=amount)
        {
            take_k=func(coins,dp,amount-coins[i],i);
            // take_s=func(coins,amount-coins[i],i+1);
        }
        skip=func(coins,dp,amount,i+1);
        return dp[i][amount]=take_k+take_s+skip;
        
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return func(coins,dp,amount,0);
    }
};