class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int>pq;
        for(auto it:nums)
        {
            pq.push(it);
        }
        while(k>0)
        {
            int num=pq.top();
            pq.pop();
            ans+=num;
            pq.push(ceil(num/3.0));
            k--;
        }
        return ans;
    }
};