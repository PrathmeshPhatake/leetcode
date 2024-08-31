class Solution {
public:
    void sub(vector<vector<int>>& ans, vector<int>& temp, vector<bool>& visited,
             vector<int> nums, int n) {
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;

            visited[i] = true;
            temp.push_back(nums[i]);
            sub(ans, temp, visited, nums, n);
            temp.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        sub(ans, temp, visited, nums, nums.size());
        return ans;
    }
};