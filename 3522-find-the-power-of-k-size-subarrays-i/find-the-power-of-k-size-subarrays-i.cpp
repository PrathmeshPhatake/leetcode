class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        if(k>n)return {-1};
        for(int i=0;i<n-k+1;i++)
        {
            bool flag=true;
            for(int j=i;j<i+k-1;j++)
            {
                if(nums[j]!=nums[j+1]-1)
                {
                   flag=false;
                   break;
                }
            }
            if(!flag)
            {
                ans.push_back(-1);
            }
            else
            {
               ans.push_back(nums[i+k-1]);
            }
        }
        return ans;
    }
};