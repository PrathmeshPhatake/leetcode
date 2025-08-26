class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int maxlen=1;
        int start=0;
        // same char of len 1 is palidrome
        for(int i=0;i<n;i++)
        {
            dp[i][i]=true;
        }
        // len 2 for direct handling
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                start=i;
                maxlen=2;
            }
        }
        for(int len =3;len<=n;len++){
            for(int i=0;i<=(n-len);i++)
            {
                int j=i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1])
                {
                    dp[i][j]=true;
                    if(maxlen<len)
                    {
                        maxlen=len;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};