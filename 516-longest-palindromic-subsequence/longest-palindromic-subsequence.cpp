class Solution {
public:
int func(string& s,string& t)
{
    int n=s.size();
    int m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    // base case at 0 its 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {

            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        return func(s,t);
    }
};