class Solution {
public:
bool func(vector<int>&nums,int k,int limit)
{
    int count=0;
    int sum=0;
    for(auto it:nums)
    {
        if(sum+it<=limit)
        {
            sum+=it;
        }else
        {
            count++;
            sum=it;
        }
    }
    if(sum!=0)count++;
    return count<=k;
}
    int splitArray(vector<int>& nums, int k) {
        int mini=*max_element(nums.begin(),nums.end());
        int maxi=0;
        int ans=0;
        for(auto it:nums)
        {
            maxi+=it;
        }
        while(mini<=maxi){
            int mid=(maxi+mini)/2;
            if(func(nums,k,mid))
            {
                ans=mid;
                maxi=mid-1;
            }else
            {
                mini=mid+1;
            }
        }
        return ans;
    }
};