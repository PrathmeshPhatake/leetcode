class Solution {
public:
int func(vector<int>&nums,vector<vector<int>>&dp,int i,int prev_i)
{
    int n=nums.size();
    if(i==n)return 0;
    if(dp[i][prev_i+1]!=-1) return dp[i][prev_i+1];
    int take=0;
    int non_take=0+func(nums,dp,i+1,prev_i);
    if( prev_i==-1||nums[i]>nums[prev_i])
    {
        take=1+func(nums,dp,i+1,i);
    }
    
    return dp[i][prev_i+1]=max(take,non_take);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // we used n+1 bcz of we have we want prev_i start -1 when prev_i =-1 then get overflow
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return func(nums,dp,0,-1);
    }
};