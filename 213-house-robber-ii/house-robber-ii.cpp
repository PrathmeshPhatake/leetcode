class Solution {
public:
int helper(vector<int>&nums,int start,int end)
{
    if(end==start)return nums[start];
    int prev2=0;
    int prev1=0;
    for(int i=start;i<=end;i++)
    {
        int current =max(prev1,nums[i]+prev2);
        prev2=prev1;
        prev1=current;
    }
    return prev1;
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        
        // igonore last home   or igoner first home
        return max(helper(nums,0,n-2),helper(nums,1,n-1));
    }
};