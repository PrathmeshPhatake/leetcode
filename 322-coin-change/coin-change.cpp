class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX - 1));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int index = 1; index <= n; index++) {
            for (int target = 1; target <= amount; target++) {
                // Not taking the current coin
                dp[index][target] = dp[index - 1][target];

                // If we can take the current coin, take it and update dp
                if (coins[index - 1] <= target) {
                    dp[index][target] = min(dp[index][target], 1 + dp[index][target - coins[index - 1]]);
                }
            }
        }

        return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
    }
};
