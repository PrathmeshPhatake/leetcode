class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>mp;
        int l=0;
        for(int r=0;r<nums.size();r++)
        {
            if(r-l>k)
            {
                mp.erase(nums[l]);
                l++;
            }
            if(mp.find(nums[r])!=mp.end())
            {
                return true;
            }
            mp.insert(nums[r]);
        }
        return false;
    }
};