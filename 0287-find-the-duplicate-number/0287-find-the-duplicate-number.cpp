class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
       map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            
        }
        for(auto c:mp)
        {
            if(c.second>1)
            {
                return c.first;
            }
        }
        return -1;
    }
};