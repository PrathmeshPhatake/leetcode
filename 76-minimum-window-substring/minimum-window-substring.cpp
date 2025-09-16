class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        vector<int> freq(256, 0);
        for (char c : t) freq[c]++;

        int left = 0, right = 0, minlen = INT_MAX, start = 0;
        int n=s.size();
        int m=t.size();
        int cnt=0;
        int required = t.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(freq[s[i]]>0) cnt++;
            freq[s[i]]--;
            while(cnt==m)
            {
                if(i-j+1<minlen)
                {
                    minlen=i-j+1;
                    start=j;
                }
                freq[s[j]]++;
                if(freq[s[j]]>0)cnt--;
                j++;
            }

        }
  return minlen == INT_MAX ? "" : s.substr(start, minlen);    }
};
