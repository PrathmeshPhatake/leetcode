class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(auto it:nums)
        {
            total+=it;
        }
        if(total%2!=0) return false;
        int tar=total/2;
        vector<vector<int>>dp(n,vector<int>(tar+1,0));
        // base case 
        // target is 0 it return true
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1;
        }
        if(nums[0]<=tar) dp[0][nums[0]]=1;
        // bootm up approches 
        for(int index=1;index<n;index++)
        {
            for(int target=1;target<=tar;target++)
            {
                int non_taken=dp[index-1][target];
                int taken =0;
                if(nums[index]<=target)
                {
                    taken =dp[index-1][target-nums[index]];
                }
               dp[index][target]=taken || non_taken;
            }
        }
        return dp[n-1][tar]==1;
    }
};