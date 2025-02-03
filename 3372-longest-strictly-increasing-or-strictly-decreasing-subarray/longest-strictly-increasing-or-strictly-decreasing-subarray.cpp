class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        int maxcount=1;
        int incount=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
              incount++;
              maxcount=max(maxcount,incount);
            }
            else
            {
                incount=1;
            }
        }
        int decount=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            {
              decount++;
              maxcount=max(maxcount,decount);
            }
            else
            {
                decount=1;
            }
        }
        return maxcount;
    }
};