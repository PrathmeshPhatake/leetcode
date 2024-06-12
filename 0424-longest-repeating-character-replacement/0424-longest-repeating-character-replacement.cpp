class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen=0;
        for(int i=0;i<s.size();i++)
        {
            vector<int >ans(26,0);
            int maxfq=0;
            for(int j=i;j<s.size();j++)
            {
                ans[s[j]-'A']++;
                maxfq = std::max(maxfq, static_cast<int>(ans[s[j]-'A']));

                int capacity=(j-i+1)-maxfq;
                if(capacity <= k)
                {
                    maxlen=max(maxlen,j-i+1);

                }
                else
                {
                    break;
                }
            }

        }
        return maxlen;
    }
};