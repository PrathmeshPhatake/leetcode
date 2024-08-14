// time complexity O(N*LOG(N))
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Step 1: Sort the array
        int n = nums.size();
        int low = 0, high = nums.back();
        
        // Binary search on the distance
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countPairs(nums, mid) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

private:
    // Function to count pairs with distance <= mid
    int countPairs(const vector<int>& nums, int mid) {
        int n = nums.size();
        int count = 0, j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && nums[j] - nums[i] <= mid) {
                j++;
            }
            count += j - i - 1;
        }
        return count;
    }
};
