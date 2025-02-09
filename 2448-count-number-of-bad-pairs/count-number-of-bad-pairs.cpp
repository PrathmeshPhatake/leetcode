class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long  n=nums.size();
        long long  count=0;
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++)
        {
            int key=nums[i]-i;
            count+=freq[key];
            freq[key]++;
        }
    return (n * (n - 1)) / 2 - count;
    }
};