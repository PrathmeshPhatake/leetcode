class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // observation for this
        // odd neg
        // even neg
        // zero in 
        // we get max of pre and suf and if zero comes then make to 1 means newly start pre or sufix
        int pre=1;
        int suf=1;
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(pre==0)pre=1;
            if(suf==0) suf=1;
            pre*=nums[i];
            suf*=nums[n-i-1];
            maxi=max(maxi,max(pre,suf));
        }
        return maxi;
    }
};