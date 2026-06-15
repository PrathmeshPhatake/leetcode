class Solution {
    public int maxProfit(int[] prices) {
        int profit=0;
        int buy=Integer.MAX_VALUE;
        for(int it:prices)
        {
            if(it<buy)
            {
                buy=it;
            }else
            {
                profit=Math.max(profit,it-buy);

            }
        }
        return profit;
    }
}