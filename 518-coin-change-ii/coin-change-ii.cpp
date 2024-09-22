class Solution {
public:
int counting(vector<vector<int>>&dp,vector<int>&coins,int index,int amount)
{
    if(index==0)
    {
        if(amount==0  )
        {
            return 1;
        }
    }
    
    if(index<0) return 0;
    if(dp[index][amount]!=-1) return dp[index][amount];
    int non_taken=counting(dp,coins,index-1,amount);
    int taken=0;
    if(coins[index]<=amount)
    {
        taken=counting(dp,coins,index,amount-coins[index]);
    }
    return dp[index][amount]=taken+non_taken;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return counting(dp,coins,n-1,amount);
    }
};