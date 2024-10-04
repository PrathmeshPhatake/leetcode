class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int total=0;
        
        for(auto it:nums)
        {
            total+=it-mini;
        }
        return total;
    }
};