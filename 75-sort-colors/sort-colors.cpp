class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            int temp=i;
            for(int j=0;j<i;j++)
            {
                if(nums[j]>nums[temp])
                {
                    temp=j;
                }
            }
            swap(nums[temp],nums[i]);
        }
        nums;
    }
};