class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum = (totalSum + num) % p; // Get the total sum modulo p
        }

        if (totalSum == 0) return 0; // No subarray needs to be removed

        unordered_map<int, int> prefixMap;
        prefixMap[0] = -1; // To handle cases where the subarray starts from the beginning
        int prefixSum = 0;
        int minLength = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            prefixSum = (prefixSum + nums[i]) % p;
            int target = (prefixSum - totalSum + p) % p; // Calculate the required modulo

            if (prefixMap.find(target) != prefixMap.end()) {
                minLength = min(minLength, i - prefixMap[target]);
            }

            // Store the current prefix modulo in the map
            prefixMap[prefixSum] = i;
        }

        return minLength == nums.size() ? -1 : minLength;
    }
};
