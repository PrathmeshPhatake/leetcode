class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0;  
        int currentMax = 0, currentMin = 0;  

        for (int num : nums) {
            currentMax = max(num, currentMax + num);  // Kadane for max sum
            currentMin = min(num, currentMin + num);  // Kadane for min sum
            maxSum = max(maxSum, currentMax);
            minSum = min(minSum, currentMin);
        }

        return max(maxSum, abs(minSum));  // Maximum absolute sum
    }
};