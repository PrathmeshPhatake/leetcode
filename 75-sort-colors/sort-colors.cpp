class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int,int>>sorted(mp.begin(),mp.end());
        sort(sorted.begin(),sorted.end(),[](auto &a,auto &b){
            if(a.second==b.second)
            {
                return a.first<b.first;
            }
            return a.first<b.first;
        });
        nums.clear();
        for(auto it:sorted){
            for(int i=0;i<it.second;i++)
            {
                nums.push_back(it.first);
            }
        }
        
    }
};