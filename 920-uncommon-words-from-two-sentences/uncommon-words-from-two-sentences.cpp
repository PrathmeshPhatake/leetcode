class Solution {
    void counting(string &str,map<string,int>&mp)
    {
        istringstream stream(str);
        string word;
        while(stream>>word)
        {
            mp[word]++;
        }
    }
    void findword(vector<string>&ans,map<string,int>&mp1,map<string,int>&mp2,string s1,string s2)
    {
        for(auto it :mp1)
        {
            if(it.second==1 && mp2.find(it.first)==mp2.end())
            {
                ans.push_back(it.first);
            }
        }
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int>mp1;
        map<string,int>mp2;
        counting(s1,mp1);
        counting(s2,mp2);
        vector<string>ans;
        findword(ans,mp1,mp2,s1,s2);
        findword(ans,mp2,mp1,s2,s1);
        return ans;
    }
};