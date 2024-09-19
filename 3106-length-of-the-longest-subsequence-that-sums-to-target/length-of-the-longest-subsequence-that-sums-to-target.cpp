class Solution {
public:
// answer-base-answer
int helper(vector<vector<int>>&dp,vector<int>&nums,int index,int target)
{
    // base case
    if(target==0) return 0;
    if(target<0 || index<0)return INT_MIN;
    if(dp[index][target]!=-1) return dp[index][target];

    // take or not take
    int take=1+helper(dp,nums,index-1,target-nums[index]);
    int non_take=helper(dp,nums,index-1,target);
    return dp[index][target]=max(take,non_take);
}
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        int ans=helper(dp,nums,n-1,target);
        return ans>0?ans:-1;
    }
};