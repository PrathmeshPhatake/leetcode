class Solution {
public:
    int func(vector<int>& nums, int k) {
        if(k==0) return 0;
        int left = 0;
        int maxi = 0;
        int n=nums.size();
        unordered_map<int, int> mp;
        for (int right = 0; right < n; right++) {
            mp[nums[right]]++;
            while (mp.size() > k && left<right) {
                mp[nums[left]]--;
                if(mp[nums[left]]==0) mp.erase(nums[left]);
                left++;
            }
            maxi +=(right - left + 1);
        }
        return maxi;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
};