class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        int subsetsum=(totalsum-target)/2;
        if(totalsum<target || (totalsum-target)%2!=0) return 0;
        vector<vector<int>>dp(n+1,vector<int>(subsetsum+1,0));
        for(int i=0;i<n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=subsetsum;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=nums[i-1])
                {
                    dp[i][j]+=dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][subsetsum];
    }
};