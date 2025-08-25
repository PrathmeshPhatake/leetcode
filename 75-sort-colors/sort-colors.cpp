class Solution {
public:
void merge(vector<int>&nums,int low,int mid,int high)
{
    vector<int>ans;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high)
    {
        if(nums[left]<=nums[right])
        {
            ans.push_back(nums[left]);
            left++;
        }
        else
        {
            ans.push_back(nums[right]);
            right++;
        }
    }
    while(left<=mid)
    {
         ans.push_back(nums[left]);
         left++;
    }
        while(right<=high)
    {
         ans.push_back(nums[right]);
         right++;
    }
    for(int i=low;i<=high;i++)
    {
        nums[i]=ans[i-low];
    }

}
void mergesort(vector<int>&nums,int left,int  right)
{
    if(left>=right) return;
    int mid=(left+right)/2;
    mergesort(nums,left,mid);
    mergesort(nums,mid+1,right);
    merge(nums,left,mid,right);
}
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        
    }
};