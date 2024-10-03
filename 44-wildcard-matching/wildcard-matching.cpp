class Solution {
public:
// passed  p and s  P contain * and ? 
bool checker(string& p, string& s,int i,int j,vector<vector<int>>&dp)
{
    if(i<0 && j<0) return 1;
    if(i<0 && j>=0) return 0;
    if(j<0)
    {
        while(i>=0)
        {
            if(p[i]!='*') return 0;
            i--;
        }
        return 1;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(p[i]==s[j] || p[i]=='?') {
        return dp[i][j]=checker(p,s,i-1,j-1,dp);
    }
    if(p[i]=='*')
    {
        return dp[i][j]=checker(p,s,i-1,j,dp) ||  checker(p,s,i,j-1,dp);
    }
    return dp[i][j]=0;
}
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // passed m-1,n-1
        return checker(p,s,m-1,n-1,dp);
    }
};