#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();
        deque<int> maxDeque, minDeque; // To maintain indices of maximum and minimum values in the current window
        int left = 0;

        for (int right = 0; right < n; ++right) {
            // Maintain maxDeque for maximum value
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);

            // Maintain minDeque for minimum value
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);

            // Shrink the window if max - min > 2
            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                if (maxDeque.front() == left) maxDeque.pop_front();
                if (minDeque.front() == left) minDeque.pop_front();
                left++;
            }

            // Add all subarrays ending at `right`
            count += (right - left + 1);
        }

        return count;
    }
};
