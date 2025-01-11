class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k)return false;
        map<char,int>mp;
        int count=0;
        for(auto it:s)
        {
            mp[it]++;
        }
        map<int,int>counting;
        for(auto it:mp)
        {
            counting[it.second]++;
        }
        for(auto it:counting)
        {
            if(it.first%2!=0)
            {
                count+=it.second;
            }
        }
         if(count>k)return false;
         return true;
    }
};