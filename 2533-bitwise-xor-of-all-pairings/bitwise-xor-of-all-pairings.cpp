class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xorNums1 = 0, xorNums2 = 0;

        // XOR all elements in nums1
        for (int num : nums1) {
            xorNums1 ^= num;
        }

        // XOR all elements in nums2
        for (int num : nums2) {
            xorNums2 ^= num;
        }

        // Calculate result based on parity of array sizes
        int result = 0;
        if (nums1.size() % 2 != 0) {
            result ^= xorNums2;
        }
        if (nums2.size() % 2 != 0) {
            result ^= xorNums1;
        }

        return result;
    }
};
