class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string ans="";
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int l=1;l<=n;l++){
            for(int i=0;i+l-1<n;i++)
            {
                int j=i+l-1;
                if(l==1)
                {
                    dp[i][j]=true;
                }else if(l==2)
                {
                    dp[i][j]=(s[i]==s[j]);
                }else
                {
                    // third element 
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j] && l>ans.size())
                {
                    ans=s.substr(i,l);
                }
            }
        }
        return ans;
    }
};