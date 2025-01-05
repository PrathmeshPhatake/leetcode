class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=shifts.size();
        vector<long long >prefix(n+1,0);
        for(int i=n;i>0;i--)
        {
            prefix[i-1]=prefix[i]+shifts[i-1];
        }
        for(int i=0;i<n;i++)
        {
            s[i]=(s[i]-'a'+prefix[i])%26+'a';
        }
        return s;
    }
};