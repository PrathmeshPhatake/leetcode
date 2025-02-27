class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        unordered_map<int, int> dp;
        int maxLen = 0;

        // Store indices of elements for quick lookup
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        // Memoized recursive function
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            int prev = arr[j] - arr[i];

            // If previous number doesn't exist before i, return 2 (minimum valid length)
            if (index.find(prev) == index.end() || index[prev] >= i) {
                return 2;
            }

            int k = index[prev];
            if (dp.find(k * n + i) != dp.end()) {
                return dp[k * n + i]; // Return memoized result
            }

            dp[k * n + i] = dfs(k, i) + 1; // Memoize result
            return dp[k * n + i];
        };

        // Iterate over all pairs (i, j)
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                maxLen = max(maxLen, dfs(i, j));
            }
        }

        return maxLen > 2 ? maxLen : 0; // If no valid sequence found, return 0
    }
};
