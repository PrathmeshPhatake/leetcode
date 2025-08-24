class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int maxi = 0;
        int zero = 0;
        int one = 0;
        while (i < n) {
            if (nums[i] == 1) {
                one++;
            } else {
                zero++;
            }
            while (zero > 1) {
                if (nums[j] == 1) {
                    one--;
                } else {
                    zero--;
                }
                j++;
            }
            i++;
            maxi=max(maxi,one+(zero-1));
        }
        return maxi;
    }
};