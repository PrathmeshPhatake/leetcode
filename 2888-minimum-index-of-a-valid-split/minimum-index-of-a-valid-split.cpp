class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            
        }
        int count=0;
        int dom=-1;
        for(auto [ele,c]:mp)
        {
            if(c>n/2)
            {
                count=c;
                dom=ele;
            }
        }
        int leftcount=0;
        int leftsize=0;
        int rightcount=0;
        int rightsize=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==dom) leftcount++;
            leftsize=i+1;
            rightcount=count-leftcount;
            rightsize=n-leftsize;
            if(leftcount>leftsize/2 && rightcount>rightsize/2)
            {
                return i;
            }
        }
        return -1;
    }
};