class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]<target)
            {
                l=mid+1;
            }
            else if(nums[mid]>target)
            {
                r=mid-1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};