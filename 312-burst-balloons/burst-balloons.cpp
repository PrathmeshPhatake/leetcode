class Solution {
public:
int func(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
{
    if(i>j)return 0;
    int maxi=INT_MIN;
    if(dp[i][j]!=-1)return dp[i][j];
    for(int k=i;k<=j;k++)
    {
        int sum=(nums[i-1]*nums[k]*nums[j+1])+func(i,k-1,nums,dp)+func(k+1,j,nums,dp);
        maxi=max(maxi,sum);
    }
    return dp[i][j]=maxi;
}
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int m=nums.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return func(1,m-2,nums,dp);
    }
};