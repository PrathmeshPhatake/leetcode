class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq(nums.begin(),nums.end());
        int count=0;
        while(pq.top()<k && pq.size()>=2)
        {
            long long temp1=pq.top();
            pq.pop();
            long long temp2=pq.top();
            pq.pop();
            pq.push(min(temp1,temp2)*2 +max(temp1,temp2));
            count++;

        }
        return count;
    }
};