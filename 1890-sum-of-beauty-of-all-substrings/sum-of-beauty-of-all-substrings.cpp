class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
           vector<int>mp(26,0);
            for (int j = i; j < n; j++) {
            int maxfreq = 0;
            int minfreq = INT_MAX;
                mp[s[j]-'a']++;
                for(auto it:mp)
                {
                    if(it>0)
                    {
                        maxfreq=max(maxfreq,it);
                        minfreq=min(minfreq,it);
                    }
                }
                ans += abs(maxfreq - minfreq);
            }
        }
        return ans;
    }
};