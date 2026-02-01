class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX;
        int sell=INT_MIN;
        int n=prices.size();
        int profit=0;
        for(int i=0;i<n;i++)
        {
            if(prices[i]<buy)
            {
                buy=prices[i];
                sell=prices[i];
            }else
            {
                sell=prices[i];
                profit=max(profit,sell-buy);
            }
        }
        return profit;
    }
};