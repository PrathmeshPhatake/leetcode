class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>nums;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(),nums.end());
        int rem=nums[0]%x;
         n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%x!=rem)
            {
                return -1;
            }
        }
        int median=nums[n/2];
        int total=0;
        for(int i=0;i<n;i++)
        {
            total+=abs(median-nums[i])/x;
        }
        return total;
    }
};