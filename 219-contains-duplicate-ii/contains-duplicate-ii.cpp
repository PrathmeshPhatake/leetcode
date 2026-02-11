class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int>st;
        int l=0;
        for(int r=0;r<n;r++){
            if(r-l>k)
            {
                st.erase(nums[l]);
                l++;
            }
            if(st.find(nums[r])!=st.end())
            {
                return true;
            }
            st.insert(nums[r]);   
        }
        return false;
    }
};