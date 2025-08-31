class Solution {
public:
int func(vector<vector<int>>&dp,vector<int>&nums,int i,int previ)
{
    int n=nums.size();
    if(i==n)
    {
        return 0;
    }
    int take=0;
    int ntake=0;
    // we used prev index element and this is firtsly is -1 so we can achived it 
    if(dp[i][previ+1]!=-1) return dp[i][previ+1];
    if(previ==-1 || nums[i]>nums[previ])
    {
        take=1+func(dp,nums,i+1,i);
    }
    ntake=func(dp,nums,i+1,previ);
    return dp[i][previ+1]=max(take,ntake);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return func(dp,nums,0,-1);
    }
};