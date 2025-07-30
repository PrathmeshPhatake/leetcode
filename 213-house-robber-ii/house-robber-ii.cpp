class Solution {
public:
int func(int start,int end,vector<int>&nums)
{
    int prev1=0;
    int prev2=0;
    for(int i=start;i<=end;i++)
    {
        int curr=max(prev1,(nums[i]+prev2));
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        
        int case1=func(0,n-2,nums);
        int case2=func(1,n-1,nums);
        return max(case1,case2);

    }
};