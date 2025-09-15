class Solution {
public:
int func(vector<int>&nums,int k)
{
    if(k<0) return 0;
        int left=0;
        int right=0;
        int count=0;
        int sum=0;
        int n=nums.size();
        while(right<n)
        {
            sum+=(nums[right]%2);
            while(sum>k){
                sum-=(nums[left]%2);
                left++;
            }
            count+=(right-left);
            
            right++;
        }
        return count;
}

    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
};