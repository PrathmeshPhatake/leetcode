class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int maxi=-1;
        for(int j=n-1;j>0;j--)
        {
            for(int i=0;i<j;i++)
            {
                if(nums[j]>nums[i])
                {
                    maxi=max(maxi,nums[j]-nums[i]);
                }
            }
        }
        return maxi;

    }
};