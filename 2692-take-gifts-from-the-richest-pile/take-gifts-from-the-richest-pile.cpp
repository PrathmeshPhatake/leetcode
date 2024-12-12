class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // max heap
        long long sum=0;
        priority_queue<int>pq;
        for(auto it:gifts)
        {
            pq.push(it);
        }
        while(k--)
        {
            int value=pq.top();
            pq.pop();
            pq.push(sqrt(value));
        }
        while(!pq.empty())
        {
            int value=pq.top();
            pq.pop();
            sum+=value;
        }
        return sum;
    }
};