class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        // sort(mp.begin(),mp.end());
        vector<pair<char,int>>nums(mp.begin(),mp.end());
        sort(nums.begin(),nums.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            if(a.second==b.second)
            {
                return a.first<b.first;
            }
            return a.second>b.second;
        });
        string ans="";
        for(auto it:nums)
        {
            for(int i=1;i<=it.second;i++)
            {
                ans+=it.first;
            }   
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};