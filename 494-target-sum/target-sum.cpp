class Solution {
public:
int func(vector<vector<int>>&dp,vector<int>nums,int index,int target)
{
    if(index==0)
    {
        if(target==0 && nums[0]==0) return 2;
        if(target==0 || nums[0]==target) return 1;
        return 0;
    }

    if(dp[index][target]!=-1) return dp[index][target];
    int non_taken=func(dp,nums,index-1,target);
    int taken=0;
    if(nums[index]<=target)
    {
        taken=func(dp,nums,index-1,target-nums[index]);
    }
    return dp[index][target]=non_taken+taken;
}

    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(auto it:nums)
        {
            total+=it;

        }
        int n=nums.size();
         if(total-abs(target)<0 || (total-target)%2!=0) return false;
        int sum=(total+target)/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return func(dp,nums,nums.size()-1,sum);
    }
};