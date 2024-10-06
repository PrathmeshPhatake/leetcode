class Solution {
public:
int counting(vector<vector<int>>&dp,vector<int>prices,int index,int buy)
{
    int n=prices.size();
    int sum=0;
    if(index>=n)
    {
        return 0;
    }
    if(buy)
    {
        sum=max(-prices[index]+counting(dp,prices,index+1,0),0+counting(dp,prices,index+1,1));
    }
    else
    {
       sum=max(prices[index]+counting(dp,prices,index+1,1),0+counting(dp,prices,index+1,0));   
    }
    return sum;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
       dp[0][0]=0;
       dp[0][1]=-prices[0];
       for(int i=1;i<n;i++)
       {
          dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
          dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
       }
       return dp[n-1][0];
    }
};