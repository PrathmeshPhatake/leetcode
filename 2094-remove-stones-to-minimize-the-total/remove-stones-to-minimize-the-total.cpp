class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
         int sum=0;
        for(auto it:piles)
        {
            pq.push(it);
            sum+=it;
        }
       while(k--)
       {
         int value=pq.top();
         pq.pop();
         sum-=(floor(value/2));
         pq.push(value-floor(value/2));
       }
       return sum;
        
    }
};