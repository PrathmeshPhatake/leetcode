class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<int> window; 
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > indexDiff) {
                window.erase(window.find(nums[i - indexDiff - 1]));
            }

            auto pos = window.lower_bound(nums[i] - valueDiff); 
            if (pos != window.end() && abs(*pos - nums[i]) <= valueDiff) {
                return true;
            }

            window.insert(nums[i]);
        }

        return false;
    }
};
