class Solution {
    public boolean func(int []nums,int i,int target,int [][]dp)
    {
        if(target==0) 
        {return true;}
        int n=nums.length;
        if(i==n)
        {return false;}
        if(dp[i][target]!=-1) {
            return dp[i][target]==1;
        }
        boolean take=false;
        if(nums[i]<=target)
        {
            take=func(nums,i+1,target-nums[i],dp);
        }
        boolean ntake=func(nums,i+1,target,dp);
        dp[i][target]=(take || ntake)?1:0;
        return take||ntake;
    }
    public boolean canPartition(int[] nums) {
        int n=nums.length;
        int sum=0;
        for(int num:nums)
        {
            sum+=num;
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        boolean  [][]dp= new boolean[n][target+1];
        for(boolean []row:dp)
        {
            Arrays.fill(row,false);
        }
        // return func(nums,0,target,dp);
        // 1 base case if sum is 0 
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        if(nums[0]<=target) dp[0][nums[0]]=true;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                boolean ntake=dp[i-1][j];
                boolean take=false;
                if(nums[i]<=j)
                {
                    take=dp[i-1][j-nums[i]];
                }
                dp[i][j]=take||ntake;
            }
        }
        return dp[n-1][target];
    }
}