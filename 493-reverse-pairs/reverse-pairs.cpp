class Solution {
public:
void merge(vector<int>&nums,int low,int mid,int high)
{
    int left=low;
    vector<int>temp;
    int right=mid+1;
    while(left<=mid &&right<=high)
    {
        if(nums[left]<=nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }else
        {
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(nums[right]);
        right++;
    }
    for(int i=low;i<=high;i++)
    {
        nums[i]=temp[i-low];
    }
}
int countpairs(vector<int>&nums,int low,int mid,int high){
    int count=0;
    int right=mid+1;
    for(int i=low;i<=mid;i++)
    {
        while(right<=high && (long long)nums[i]>(2LL*nums[right]))
        {
            right++;
        }
        count+=(right-(mid+1));
    }
    return count;
}
int mergesort(vector<int>&nums,int low,int high)
{
    if(low>=high) return 0;
    int mid=(low+high)/2;
    int cnt=0;
    cnt+=mergesort(nums,low,mid);
    cnt+=mergesort(nums,mid+1,high);
    cnt+=countpairs(nums,low,mid,high);
    merge(nums,low,mid,high);
    return cnt;
}
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};