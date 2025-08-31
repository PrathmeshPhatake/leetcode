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
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // return func(dp,nums,0,-1);
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i-1;j>=-1;j--)
            {
                int take=0;
                if(j==-1 || nums[i]>nums[j])
                {
                    take=1+dp[i+1][i+1];
                }
                int ntake=dp[i+1][j+1];
                dp[i][j+1]=max(take,ntake);
            }
        }
        return dp[0][0];

    }
};