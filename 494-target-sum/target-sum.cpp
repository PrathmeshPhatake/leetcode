class Solution {
public:
void func(vector<int>&nums,int target,int sum,int i,int& count)
{
    int n=nums.size();
    if(i==n)
    {
        if(sum==target)
        {
            count++;
        }
        return;
    }
    func(nums,target,-1*nums[i]+sum,i+1,count);
    func(nums,target,1*nums[i]+sum,i+1,count);
}
    int findTargetSumWays(vector<int>& nums, int target) {
       int count=0;
       func(nums,target,0,0,count);
       return count;
    }
};