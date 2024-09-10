class Solution {
public:
    int money(vector<int>& nums, int home, vector<int>& dp) {
        int n = nums.size();
        if (home >= n) {
            return 0;
        }

        if (dp[home] != -1)
            return dp[home];

           int  left = nums[home] + money(nums, home + 2, dp);

           int  right = nums[home] + money(nums, home + 3, dp);
        return dp[home] = max(left, right);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        return max(money(nums, 0, dp1),money(nums, 1, dp2));
    }
};