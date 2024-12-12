class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>pq;
        double sum=0.0;
        for(auto it:nums){
            pq.push(it);
            sum+=it;
        }
        sum=sum/2;
        int count=0;
        while(sum>0)
        {
            double value=pq.top();
            pq.pop();
            pq.push(value-(value/2));
            sum-=value/2;
            count++;
        }
        return count;
    }
};