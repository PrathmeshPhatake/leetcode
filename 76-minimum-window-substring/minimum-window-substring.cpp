class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freq(256,0);
        for(char c:t) freq[c]++;
        int j=0;
        int n=s.size();
        int m=t.size();
        int maxlen=INT_MAX;
        int start=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(freq[s[i]]>0) cnt++;
            freq[s[i]]--;
            while(cnt==m){
                if(i-j+1<maxlen)
                {
                    maxlen=i-j+1;
                    start=j;
                }
                freq[s[j]]++;
                if(freq[s[j]]>0) cnt--;
                j++;
            }
        }
        return maxlen==INT_MAX?"":s.substr(start,maxlen);
    }
};