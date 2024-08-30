class Solution {
    public:
    void sub(vector<vector<int>>&ans,vector<int>&temp,int n,int i,vector<int>nums)
    {
        if(i==n)
        {
            ans.push_back(temp);
        }
        if(i<n)
        {
            temp.push_back(nums[i]);
            sub(ans,temp,n,i+1,nums);
            temp.pop_back();
            sub(ans,temp,n,i+1,nums);
            i++;
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        sub(ans,temp,n,0,nums);
        return ans;
    }
};