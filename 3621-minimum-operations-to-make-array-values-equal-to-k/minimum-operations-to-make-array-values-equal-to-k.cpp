class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
           mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            if(it.first>k)
            {
                count++;
            }else if(it.first<k)
            {
                return -1;
            }

        }
        return count;
    }
};