class Solution {
public:
int func(vector<int>&nums,int limit,int k)
{
    int n=nums.size();
    int prev=0;
    int count=1;
    for(int i=0;i<n;i++)
    {
        if(prev+nums[i]>limit)
        {
            count++;
            prev=nums[i];
        }else
        {
            prev+=nums[i];
        }
        
    }
    return count;
}
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        // for(int i=maxi;i<=sum;i++)
        // {
        //     if(func(nums,i,k)==true)
        //     {
        //         return i;
        //     }
        // }
        int left=maxi;
        int right=sum;
        while(left<=right)
        {
            int mid=(left+right)/2;
            int partion=func(nums,mid,k);
            if(partion>k)
            {
                left=mid+1;
            }else
            {
                right=mid-1;
            }
        }
        return left;
    }
};