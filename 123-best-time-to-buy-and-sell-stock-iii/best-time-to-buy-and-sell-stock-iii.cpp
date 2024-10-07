class Solution {
public:
int counting(vector<vector<vector<int>>>&dp,vector<int>&prices,int index,int buy,int count)
{
    int n=prices.size();
    if(index>=n ||count>=2)
    {
        return 0;
    }
    int sum=0;
    if(dp[index][buy][count]!=-1) return dp[index][buy][count];
    if(buy)
    {
        
            sum=max(0+counting(dp,prices,index+1,1,count) // skip buy
            ,-prices[index]+counting(dp,prices,index+1,0,count));   // buy this 
    }
    else
    {
        sum=max(prices[index]+counting(dp,prices,index+1,1,count+1) // sell this product
        ,0+counting(dp,prices,index+1,0,count)); // skipp this sale 
    }
    return dp[index][buy][count]=sum;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return counting(dp,prices,0,1,0);

    }
};