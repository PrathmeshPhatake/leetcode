class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int result=0;
        int maxi=0;
        int n=s.length();
        int j=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            maxi=max(maxi,mp[s[i]]);
            while((i-j+1)-maxi>k)
            {
                mp[s[j]]--;
                j++;
            }
            result=max(result,i-j+1);
        }
        return result;
    }
};