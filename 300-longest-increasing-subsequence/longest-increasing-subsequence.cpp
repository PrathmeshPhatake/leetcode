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
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // return func(nums,dp,0,-1);
        // n--->0
        // i-1-->-1
        for(int i=n-1;i>=0;i--)
        {
            for(int prev_i=i-1;prev_i>=-1;prev_i--)
            {
                int len=0+dp[i+1][prev_i+1];
                if(prev_i==-1 ||nums[i]>nums[prev_i])
                {
                    // we pass i in prev_i
                    len=max(len,1+dp[i+1][i+1]);
                }
                 dp[i][prev_i+1]=len;
            }

        }
        return dp[0][0];
    }
};