class Solution {
public:
int func(int i,vector<int>&dp,vector<int>&nums)
{
    int n=nums.size();
    if(i>=n)
    {
        return 0;

    }
    if(dp[i]!=-1) return dp[i];
    int take=func(i+2,dp,nums)+nums[i];
    int non_take=func(i+1,dp,nums);
    return dp[i]=max(take,non_take);
    
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return func(0,dp,nums);
    }
};