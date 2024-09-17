class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0); // Total sum of the array

        int N = n / 2; // Divide the array into two parts

        // Vectors to store possible sums
        vector<vector<int>> left(N + 1), right(N + 1);

        // Generate all possible sums for the left and right halves
        for (int mask = 0; mask < (1 << N); ++mask) {
            int idx = 0, l_sum = 0, r_sum = 0;
            for (int i = 0; i < N; ++i) {
                if (mask & (1 << i)) {
                    idx++;
                    l_sum += nums[i];
                    r_sum += nums[i + N];
                }
            }
            left[idx].push_back(l_sum);
            right[idx].push_back(r_sum);
        }

        // Sort right vector for binary search
        for (int idx = 0; idx <= N; ++idx) {
            sort(right[idx].begin(), right[idx].end());
        }

        int res = INT_MAX; // Initialize result to a large number

        // Iterate over the left part
        for (int idx = 0; idx <= N; ++idx) {
            for (auto &a : left[idx]) {
                int b = (sum - 2 * a) / 2; // Value to be minimized
                int rightIdx = N - idx; // Corresponding index in right array
                auto &v = right[rightIdx]; // Vector in right part
                auto itr = lower_bound(v.begin(), v.end(), b); // Binary search

                if (itr != v.end()) {
                    res = min(res, abs(sum - 2 * (a + *itr))); // Update result
                }
                if (itr != v.begin()) {
                    res = min(res, abs(sum - 2 * (a + *(--itr)))); // Check previous element
                }
            }
        }

        return res;
    }
};
