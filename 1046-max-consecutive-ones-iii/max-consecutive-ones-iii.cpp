class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int n=nums.size();
        int maxlen=0;
        int zero=0;
        while(r<n)
        {
            if(nums[r]==0)
            {
                zero++;
            }
            if(zero<=k)
            {
                maxlen=max(maxlen,r-l+1);
            }else
            {
                while(zero>k && l<r)
                {
                    if(nums[l]==0)
                    {
                        zero--;
                    }
                    l++;
                }
            }
            r++;
        }
        return maxlen;
    }
};