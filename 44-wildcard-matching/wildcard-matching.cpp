// we compare p with s 
// take not take
class Solution {
public:
bool func(vector<vector<int>>&dp,int i,int j,string& s,string& p)
{
    if(i<0 && j<0) return 1;
    if(i>=0 && j<0) return 0;
    if(i<0)
    {
        while(j>=0)
        {
            if(p[j]!='*') return 0;
            j--;
        }
        return 1;
    } 
    if(dp[i][j]!=-1) return dp[i][j];
    // if ? comes  or both are same 
    if(p[j]=='?' || p[j]==s[i]) return dp[i][j]= func(dp,i-1,j-1,s,p);
    // IF STAR COME S THEN SKIP THIS STAR OR GET LETTER OR SKIP THIS 
    if(p[j]=='*') {
        return dp[i][j]=func(dp,i-1,j,s,p) || func(dp,i,j-1,s,p);
    }
    return dp[i][j]=0;
}
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return func(dp,n-1,m-1,s,p);
    }
};