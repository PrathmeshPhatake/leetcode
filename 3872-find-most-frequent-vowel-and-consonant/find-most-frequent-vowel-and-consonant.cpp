class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<int,int>mp;
        int maxicon=0;
        int n=s.length();
        int maxivowel=0;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            if(s[i]=='a' || s[i]=='e' ||s[i]=='i'|| s[i]=='o'||s[i]=='u')
            {
                maxicon=max(maxicon,mp[s[i]]);
            }else
            {
                maxivowel=max(maxivowel,mp[s[i]]);
            }
        }
        return maxivowel+maxicon;
    }
};