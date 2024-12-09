class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> parityChange(n - 1, true); 
        for (int i = 0; i < n - 1; i++) {
            parityChange[i] = (nums[i] % 2) != (nums[i + 1] % 2);
        }

        vector<int> prefix(n, 0);
        for (int i = 0; i < n - 1; i++) {
            prefix[i + 1] = prefix[i] + (parityChange[i] ? 0 : 1);
        }

        vector<bool> result;
        for (const auto& query : queries) {
            int i = query[0], j = query[1];
            result.push_back(prefix[j] - prefix[i] == 0);
        }

        return result;
    }
};
