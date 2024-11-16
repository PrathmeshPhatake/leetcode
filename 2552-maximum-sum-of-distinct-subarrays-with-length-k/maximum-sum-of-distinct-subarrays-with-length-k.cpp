class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        map<int, int> mp;
        long long maxi = 0;

        // Initialize the first window
        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
            maxi += nums[i];
        }

        // Check if the first window is valid
        if (mp.size() == k) ans = max(ans, maxi);

        // Slide the window
        for (int i = k; i < n; i++) {
            // Add the new element to the window
            mp[nums[i]]++;

            // Remove the element that is sliding out of the window
            if (mp[nums[i - k]] == 1) {
                mp.erase(nums[i - k]); // Erase key if count becomes 0
            } else {
                mp[nums[i - k]]--;
            }

            // Update the sum for the current window
            maxi += nums[i] - nums[i - k];

            // Check if the current window is valid
            if (mp.size() == k) {
                ans = max(ans, maxi);
            }
        }

        return ans;
    }
};
