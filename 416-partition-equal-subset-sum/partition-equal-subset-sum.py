class Solution:
    def func(self,n,i,target,nums,dp):
        if target == 0:
            return True
        
        if i == len(nums):
            return False

        if dp[i][target] != -1:
            return dp[i][target]
        
        take=False
        if nums[i]<=target:
            take=self.func(n,i+1,target-nums[i],nums,dp)
        ntake=self.func(n,i+1,target,nums,dp)

        dp[i][target]=take or ntake
        return dp[i][target]
    def canPartition(self, nums: List[int]) -> bool:
        sum=0;
        n=len(nums)
        for i in range(n):
            sum+=nums[i]
        if sum%2!=0:
            return False
        target=sum//2
        dp=[[-1]*(target+1) for _ in range(n)]
        return self.func(n,0,target,nums,dp)
        