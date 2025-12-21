class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX;
        int profit=0;
        for(auto it:prices)
        {
            if(it<=buy)
            {
                buy=it;
            }else
            {
                profit=max(profit,it-buy);
            }
        }
        return profit;
    }
};