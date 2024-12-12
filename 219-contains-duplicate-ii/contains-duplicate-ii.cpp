class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<k && i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second>=2)return true;
        }
        for(int i=k;i<n;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>=2)return true;
            mp[nums[i-k]]--;
        }
        return false;
    }
};