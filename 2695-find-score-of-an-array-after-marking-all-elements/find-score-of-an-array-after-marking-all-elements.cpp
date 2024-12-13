class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<int>visited(n,-1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
           pq.push({nums[i],i});   
        }
        while(!pq.empty())
        {
            auto [value,index]=pq.top();
            pq.pop();
            if(visited[index]!=1)
            {
                visited[index]=1;
                sum+=nums[index];

                if(index>0)
                {
                    visited[index-1]=1;

                }
                if(index<n-1)
                {
                    visited[index+1]=1;
                }
            }
            
        }
        return sum;
        
    }
};