class Solution {
public:
int func(vector<int>& nums, int k)
{
        int count=0;
        int l=0;
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int r=0;r<n;r++)
        {
            mp[nums[r]]++;
            while(mp.size()>k && l<=r){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }
            count+=r-l+1;
            
        }
        return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
};