class Solution {
public:
int func(int i,int ans,int target,vector<int>&nums)
{
    if(i<0 && target==ans)
    {
        return 1;
    }
    if(i<0)return 0;

    int positive=func(i-1,ans+(1*nums[i]),target,nums);
    int negative=func(i-1,ans+(-1*nums[i]),target,nums);
    return positive+negative;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return func(n-1,0,target,nums);
    }
};