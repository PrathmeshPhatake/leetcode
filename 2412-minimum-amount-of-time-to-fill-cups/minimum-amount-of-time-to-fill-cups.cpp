class Solution {
public:
    int fillCups(vector<int>& amount) {
        int count=0;
        priority_queue<int>pq;
        for(auto it:amount)
        {
            if(it>0)pq.push(it);

        }
        while(!pq.empty())
        {
            int first=pq.top();
            pq.pop();
            int second=0;
            if(!pq.empty())
            {
                second=pq.top();
                pq.pop();
            }
            first--;
            second--;
            if(first>0)
            {
                pq.push(first);
            }
            if(second>0)
            {
                pq.push(second);
            }
            count++;

        }
        return count;
    }
};