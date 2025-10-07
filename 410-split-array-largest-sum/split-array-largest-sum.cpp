class Solution {
public:
bool func(vector<int>&nums,int limit,int k)
{
    int sum=0;
    long long count=1;
    for(int i=0;i<nums.size();i++)
    {
        if(sum+nums[i]<=limit)
        {
            sum+=nums[i];
        }else
        {
            count++;
            sum=nums[i];
            if(count>k) return false;
        }
    }
    return true;
}
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(func(nums,mid,k))
            {
                ans=mid;
                high=mid-1;  // try lower limit
            }else
            {
                low=mid+1; // try higher limit 
            }
        }
    return ans;
    }
};