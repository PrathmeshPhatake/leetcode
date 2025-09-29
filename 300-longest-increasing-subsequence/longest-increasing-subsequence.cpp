class Solution {
public:
    int func(vector<int>& nums, int prev_ind, int ind, int n, vector<vector<int>>& dp) {
        if (ind == n) return 0;

        if (dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];

        int len = func(nums, prev_ind, ind + 1, n, dp);

        if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
            len = max(len, 1 + func(nums, ind, ind + 1, n, dp));
        }

        return dp[ind][prev_ind + 1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return func(nums, -1, 0, n, dp);
    }
};
