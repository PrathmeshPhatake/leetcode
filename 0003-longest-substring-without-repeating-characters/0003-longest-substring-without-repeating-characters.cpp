class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int maxlen=0;
        for(int i=0;i<s.size();i++)
        {
            map<char,int>mp;
            int len=0;
            for(int j=i;j<s.size();j++)
            {
                if(mp[s[j]]==1) break;
                len=j-i+1;
                maxlen=max(maxlen,len);
                mp[s[j]]=1;

            }
        }
        return maxlen;
    }
};