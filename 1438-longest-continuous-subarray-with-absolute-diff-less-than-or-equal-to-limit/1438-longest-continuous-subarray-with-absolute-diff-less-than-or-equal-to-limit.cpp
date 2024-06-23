class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> maxSet, minSet;
        int left = 0;
        int maxSize = 0;

        for (int right = 0; right < nums.size(); ++right) {
            maxSet.insert(nums[right]);
            minSet.insert(nums[right]);

            while (*maxSet.rbegin() - *minSet.begin() > limit) {
                maxSet.erase(maxSet.find(nums[left]));
                minSet.erase(minSet.find(nums[left]));
                ++left;
            }

            maxSize = max(maxSize, right - left + 1);
        }

        return maxSize;
    }
};