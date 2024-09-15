class Solution {
    int  partion(vector<int>&nums,vector<vector<int>>&dp,int index,int target)
    {
        if(target==0) return 1;
        if(index==0) return nums[0]==target ? 1:0;
        // if(index<0)return 0;
        
        if(dp[index][target]!=-1)return dp[index][target];

        int  not_taken=partion(nums,dp,index-1,target);
        int taken=0;

        if(nums[index]<=target)
        {
            taken=partion(nums,dp,index-1,target-nums[index]);
        }
        return dp[index][target]=taken || not_taken;
    }
public:
    bool canPartition(vector<int>& nums) {
        int total=0;
        int n=nums.size();
        for(auto it :nums)
        {
            total+=it;
        }
        // if total is odd then   sit not possible 
        if(total%2!=0)return false;

        int target=total/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return partion(nums,dp,n-1,total/2)==1 ;

    }
};