class Solution {
public:
int func(vector<int>&nums,vector<vector<int>>&dp,int i,int prev_i)
{
    int n=nums.size();
    if(i==n)return 0;
    if(dp[i][prev_i+1]!=-1)return dp[i][prev_i+1];
    int take=0;
    if(prev_i==-1 || nums[i]>nums[prev_i])
    {
        take=1+func(nums,dp,i+1,i);
    }
    int non_take=func(nums,dp,i+1,prev_i);
    return dp[i][prev_i+1]=max(take,non_take);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return func(nums,dp,0,-1);
    }
};