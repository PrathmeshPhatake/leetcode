class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long int ans=0;
        int maxi=-1,mini=-1,badi=-1,n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<minK || nums[i]>maxK) badi=i;
            if(nums[i]==minK) mini=i;
            if(nums[i]==maxK) maxi=i;
            ans+=max(0,min(mini,maxi)-badi);
        }
        return ans;
    }
};