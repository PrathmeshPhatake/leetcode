class Solution {
public:
    int maximumDifference(vector<int>& nums) {
     int n=nums.size();
     int maxi=nums[0];
     int mini=nums[0];
     int diff=-1;
     for(int i=1;i<n;i++)
     {
        if(nums[i]<=maxi)
        {
            maxi=nums[i];
            mini=min(mini,nums[i]);

        }
        else
        {
            maxi=max(maxi,nums[i]);
            diff=max(diff,maxi-mini);
            mini=min(mini,nums[i]);
        }
     }   
     return diff;
    }
};