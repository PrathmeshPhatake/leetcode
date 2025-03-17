class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        map<int,int>mp;
        for(auto it: nums)
        {
            mp[it]++;
        }
        for(auto it:mp)
        {
            if(it.second%2!=0)
            {
                return false;
            }
            else
            {
                total+=(it.second/2);
            }
        }
        return total==n/2;
    }
};