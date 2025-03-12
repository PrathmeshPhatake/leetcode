class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negcount=0;
        int poscount=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            {
                negcount++;
            }
            else if(nums[i]>0)
            {
                poscount++;
            }
        }
        return max(negcount,poscount);
    }
};