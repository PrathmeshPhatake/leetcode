class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return {nums[0]}; 
        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        int maxivalue=0;
        int maxindex=-1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
                {
                    dp[i]=1+dp[j];
                    parent[i]=j;
                }
            }
            if(maxivalue<dp[i])
            {
                maxivalue=dp[i];
                maxindex=i;
            }
        }
        vector<int>ans;
        for(int i=maxindex;i!=-1;i=parent[i])
        {
            ans.push_back(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};