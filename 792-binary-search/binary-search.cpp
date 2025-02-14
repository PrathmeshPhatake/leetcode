class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int n=nums.size();
        if(n==1 ) return target==nums[0]? 0:-1;
        int r=nums.size();
        int mid=(l+r)/2;
        while(l<=r)
        {
            if(nums[mid]<target)
            {
                l=mid+1;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else
            {
                return mid;
            }
            mid=(l+r)/2;
        }
        return -1;
        
    }
};