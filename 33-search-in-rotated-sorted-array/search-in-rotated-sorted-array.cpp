class Solution {
public:
int pivot(vector<int>&nums)
{
    if(nums.size()==1) return 0;
    for(int i=0;i<nums.size()-1;i++)
    {
        if(nums[i]>nums[i+1])
        {
            return i;
        }
    }
    return nums.size()-1;
}
int func(vector<int>&nums,int target,int left,int right)
{
   
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(nums[mid]<target)
        {
            left=mid+1;
        }else if(nums[mid]>target)
        {
            right=mid-1;
        }else
        {
            return mid;
        }
    }
    return -1;
}
    int search(vector<int>& nums, int target) {
        int pt=pivot(nums);
        int right=func(nums,target,0,pt);
        int left=func(nums,target,pt+1,nums.size()-1);
        if(left==-1 && right==-1)
        {
            return -1;
        }else if(left==-1)
        {
            return right;
        }
        return left;
    }
};