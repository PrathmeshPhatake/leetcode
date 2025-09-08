class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0;
        int r=0;
        int count=0;
        int n=nums.size();
        while(r<n-1)
        {
            int forhtest=0;
            for(int i=l;i<=r;i++){
                forhtest=max(forhtest,i+nums[i]);
            }
            l=r+1;
            r=forhtest;
            count++;
        }
    return count;
    }
};