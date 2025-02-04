class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        int sum = nums[0];
        int maxi = nums[0];
        
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                sum += nums[i];
            } else {
                sum = nums[i];
            }
            maxi = max(maxi, sum);
        }
        
        return maxi;
    }
};
