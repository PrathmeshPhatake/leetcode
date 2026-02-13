class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int sum=0;
        vector<int>ans;
        int l=0;
        int n=nums.size();
        // value,index
        priority_queue<pair<int,int>>pq;
        for(int r=0;r<n;r++){
           pq.push({nums[r],r});
           while(!pq.empty() && pq.top().second<=r-k)
           {
               pq.pop();
           }
           if(r>=k-1)
           {
           ans.push_back(pq.top().first);
           }
        }
        return ans;
    }
};