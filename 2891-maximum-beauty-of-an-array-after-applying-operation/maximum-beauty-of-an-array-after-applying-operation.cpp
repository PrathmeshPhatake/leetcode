class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
           while(nums[i]-nums[j]>2*k)
           {
             j++;
           }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};