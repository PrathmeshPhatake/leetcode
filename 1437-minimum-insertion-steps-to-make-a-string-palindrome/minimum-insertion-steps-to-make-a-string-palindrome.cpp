class Solution {
public:
int substring(string s,string t)
{
    int n=s.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    // base case all each element is palindromic
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[n][n];

}
    int minInsertions(string s) {
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());
        int size=substring(s,t);
        return n-size;
    }
};