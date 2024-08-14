class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // sum or position of nums2
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         vector<vector<int>>ans;
        for(int i:nums1)
        {
            pq.push({i+nums2[0],0});
        }
        while(k-- && !pq.empty())
        {
            int sum=pq.top().first;
            int  pos=pq.top().second;
            pq.pop();
            
            ans.push_back({sum-nums2[pos],nums2[pos]});

            if(pos+1<nums2.size() )
            {
                pq.push({sum-nums2[pos]+nums2[pos+1],pos+1});
            }
           
        }
        return ans;
    }
};