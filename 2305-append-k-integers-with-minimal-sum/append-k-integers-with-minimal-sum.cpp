#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    long long minimalKSum(std::vector<int>& nums, int k) {
        // Sort and remove duplicates
        std::sort(nums.begin(), nums.end());
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

        long long sum = 0, curr = 1;

        // Iterate through sorted numbers
        for (int num : nums) {
            if (k <= 0) break;

            // Add missing numbers between `curr` and `num - 1`
            if (num > curr) {
                long long gap = num - curr;
                long long take = std::min((long long)k, gap);

                // Add the sum of the first `take` numbers starting from `curr`
                sum += take * (2LL * curr + take - 1) / 2;
                k -= take;
            }

            // Move `curr` to the next number after `num`
            curr = num + 1;
        }

        // If `k` numbers are still needed, add the next `k` consecutive numbers starting from `curr`
        if (k > 0) {
            sum += k * (2LL * curr + k - 1) / 2;
        }

        return sum;
    }
};
