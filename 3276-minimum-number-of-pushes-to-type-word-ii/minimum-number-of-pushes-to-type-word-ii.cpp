//time complexity O(n)
//space O(26);
class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26);
        for(auto it:word)
        {
            freq[it-'a']++;
        }
        // sort in descending order
        sort(freq.begin(),freq.end(),greater<int>());
        int sz=0;
        int push=1;
        int ans=0;
        for(;sz<26;sz++)
        {
            if(sz>=8 && sz%8==0) push++;
            ans+=freq[sz]*push;
        }
        return ans;
    }
};