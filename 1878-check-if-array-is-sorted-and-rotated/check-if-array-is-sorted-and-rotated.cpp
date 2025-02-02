class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int pivot=-1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            {
                pivot=i;
            }
        }
        if(pivot==-1)return true;
        vector<int>ans(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            ans[i]=nums[(i+pivot)%n];
        }
        sort(nums.begin(),nums.end());
        return ans==nums;
    }
};