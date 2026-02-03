class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int maxlen=0;
        int maxfreq=0;
        int l=0;
        // replacemnt =window size-maxfreq;
        for(int r=0;r<s.size();r++)
        {
            mp[s[r]]++;
            maxfreq=max(maxfreq,mp[s[r]]);
            while((r-l+1)-maxfreq>k)
            {
                mp[s[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};