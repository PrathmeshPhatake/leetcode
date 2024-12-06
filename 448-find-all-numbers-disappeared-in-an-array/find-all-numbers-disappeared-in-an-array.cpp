class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int>num_set(nums.begin(),nums.end());
        vector<int>ans;
        int n=nums.size();
        for(int i=1;i<=n;i++)
        {
            if(num_set.find(i)==num_set.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};