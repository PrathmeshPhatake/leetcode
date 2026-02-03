class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int n=nums.size();
        int maxi=0;
        while(r<n)
        {
            if(nums[r]==0)
            {
                k--;
            }
            if(k>=0)
            {
                maxi=max(maxi,r-l+1);
            }
            if(k<0 && l<=r)
            {
                if(nums[l]==0)
                {
                    k++;
                }
                l++;
            }
            r++;
        }
        return maxi;
    }
};