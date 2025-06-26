class Solution {
public:
void backtrack(vector<vector<int>>&ans,vector<int>&subset,vector<int>&nums,int i)
{
    if(i==nums.size())
    {
        ans.push_back(subset);
        return;
    }
    // take
    subset.push_back(nums[i]);
    backtrack(ans,subset,nums,i+1);
    subset.pop_back();
    while(i+1<nums.size() && nums[i]==nums[i+1])
    {
        i++;
    }
    backtrack(ans,subset,nums,i+1);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subset;
        sort(nums.begin(),nums.end());
        backtrack(ans,subset,nums,0);
        return ans;
    }
};