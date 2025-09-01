class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        // next_permutation(nums.begin(),nums.end());
        // find piovt element
        // find exact greater element of before of pivot and replace it
        // reverse reaming part of from pivot to end of array
        int ind = -1;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin() + ind+1, nums.end());
    }
};