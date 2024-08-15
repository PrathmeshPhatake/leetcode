class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        vector<pair<char,int>>vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),[](pair<char,int>&a,pair<char,int>&b){
            if(a.second==b.second)
            {
                return a.first<b.first;
            }
            return a.second>b.second;
        });
        string str;
        for(auto it:vec)
        {
            int size=it.second;
            for(int i=0;i<size;i++)
            {
                str+=it.first;
            }
        }
        return str;
    }
};