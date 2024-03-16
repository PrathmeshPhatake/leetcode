class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int prefsum = 0, ans = 0;
        unordered_map<int, int> firstoccu{{0, -1}}; // Typo: Should be 'firstoccu[prefsum] = i;', not 'firstoccu[prefsum] = 1;'
        for (int i = 0; i < nums.size(); i++) {
            prefsum += nums[i] == 1 ? 1 : -1;
            if (firstoccu.count(prefsum)) {
                ans = max(ans, i - firstoccu[prefsum]);
            } else {
                firstoccu[prefsum] = i; // Typo: Should be 'firstoccu[prefsum] = i;', not 'firstoccu[prefsum] = 1;'
            }
        }
        return ans;
    }
};
