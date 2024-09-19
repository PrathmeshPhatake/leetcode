class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }

        // Check for impossible cases 
        // if our targe is odd then we can divide it 
        if (total < abs(target) || (total - target) % 2 != 0) return 0;

        // Calculate the subset sum we're trying to find
        int sum = (total + target) / 2;
        int n = nums.size();

        // Create a DP table with size [n+1][sum+1]
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        // Base Case: There's one way to get a sum of 0 (by picking no elements)
        for (int i = 0; i < n; ++i) {
            dp[i][0] = 1;
        }

        // Special case when nums[0] is 0
        if (nums[0] <= sum) {
            dp[0][nums[0]] += 1;
        }

        // Fill the DP table
        for (int index = 1; index < n; ++index) {
            for (int target = 0; target <= sum; ++target) {
                int non_taken = dp[index - 1][target];
                int taken = 0;
                if (nums[index] <= target) {
                    taken = dp[index - 1][target - nums[index]];
                }
                dp[index][target] = non_taken + taken;
            }
        }

        return dp[n - 1][sum];
    }
};
