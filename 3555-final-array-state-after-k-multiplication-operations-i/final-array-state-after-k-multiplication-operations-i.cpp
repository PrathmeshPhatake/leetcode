class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }
        while(k--)
        {
            auto [value,i]=pq.top();
            pq.pop();
            pq.push({value*multiplier,i});
        }
        vector<int>ans(n,-1);
        while(!pq.empty())
        {
            auto [value,i]=pq.top();
            pq.pop();
            ans[i]=value;
            
        }
        return ans;
    }
};