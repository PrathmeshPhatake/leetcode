class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int j=0;
        int n=nums.size();
        int count=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]-nums[j]>k)
            {
                j=i;
                count++;
            }

        }
        return count;
    }
};