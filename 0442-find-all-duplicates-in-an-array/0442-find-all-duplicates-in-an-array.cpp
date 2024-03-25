class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int, int>mp;
        vector<int>temp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto num : mp)
        {
            if(num.second>1)
            {
                temp.push_back(num.first);
            }
        }
        return temp;
    }
};