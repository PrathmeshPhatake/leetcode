class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int num=*max_element(nums.begin(),nums.end());
        int sum=0;
        int n=k;
        for(int i=0;i<n;i++)
        {
            sum+=num+k-1;
            k--;
        }
        return sum;
    }
};