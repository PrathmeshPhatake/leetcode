class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        string ans="";
        for(int len=1;len<=n;len++)
        {
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                // if len is 1 then 
                if(len==1) 
                {
                    dp[i][j]=true;
                }else if(len==2)
                {
                    //  if 2 then check it same or not 
                    dp[i][j]=(s[i]==s[j]);
                }else
                {
                    // if first and last is same then we can check middle one is same 
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j] && len>ans.size())
                {
                    ans=s.substr(i,len);
                }
            }
        }
        return ans;
    }
};