class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mps;
        unordered_map<char,int>mpt;
        int n=s.length();
        if(s.length()!=t.length())return false;
        for(int i=0;i<n;i++)
        {
            mps[s[i]]++;
            mpt[t[i]]++;
        }
        for(auto it:s)
        {
            if(mps[it]!=mpt[it])
            {
                return false;
            }
        }
        return true;

    }
};