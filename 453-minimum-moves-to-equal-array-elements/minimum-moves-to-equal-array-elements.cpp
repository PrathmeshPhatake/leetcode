class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int total=0;
        
        for(auto it:nums)
        {
            total+=it-nums[0];
        }
        return total;
    }
};