// find first and last occurence of element and store size of this 
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq,first,last;
        int maxQ=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            freq[num]++;
            // first
            maxQ=max(maxQ,freq[num]);
            if(first.find(num)==first.end())
            {
                first[num]=i;
            }
            last[num]=i;
        }
        int size=n;
        for(auto it:freq)
        {
            if(it.second==maxQ)
            {
                size=min(size,last[it.first]-first[it.first]+1);
                
            }
        }
        return size;
    }



};