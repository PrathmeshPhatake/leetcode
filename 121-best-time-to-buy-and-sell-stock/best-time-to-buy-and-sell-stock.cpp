class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=prices[0];
        int sell=INT_MIN;
        int diff=0;
        for(int i=0;i<n;i++){
            sell=max(sell,prices[i]);
            diff=max(diff,sell-buy);
            if(prices[i]<buy)
            {
                sell=0;
                buy=prices[i];
            }
        }
        return diff;
    }
};