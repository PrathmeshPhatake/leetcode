class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;  // Edge case for empty input
        
        int aheadBuy = 0, aheadSell = 0;  // For storing future states

       
        for (int index = n - 1; index >= 0; --index) {
            // If you are in a "buy" state, you have two choices:
            // 1. Buy the stock and move to the "sell" state.
            // 2. Skip buying and stay in the "buy" state.
            int currBuy = max(-prices[index] + aheadSell, aheadBuy);

            // If you are in a "sell" state, you have two choices:
            // 1. Sell the stock and move to the "buy" state.
            // 2. Skip selling and stay in the "sell" state.
            int currSell = max(prices[index] + aheadBuy, aheadSell);
            
            // Update the state for the next iteration
            aheadBuy = currBuy;
            aheadSell = currSell;
        }

        // The answer will be in the "buy" state for the first day (index 0).
        return aheadBuy;
    }
};
