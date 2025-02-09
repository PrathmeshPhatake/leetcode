class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        long long count=0;
        map<int,int>freq;
        for(int i=0;i<n;i++)
        {
            int res=nums[i]-i;
            count+=freq[res];
            freq[res]++;   
        }
        return (n*(n-1))/2-count;
    }
};