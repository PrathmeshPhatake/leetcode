class Solution {
public:
bool func(vector<vector<bool>>&dp,string s,string p,int i,int j)
{
    if(i==0 && j==0) return true;
    if(j==0 ) 
    {
        if(i>0) return false; 
    }
    if(dp[i][j]!=false) return dp[i][j];
    if(i==0)
    {
        if(j>0)
        {
            for(int jj=j-1;jj>=0;jj--)
            {
                if(p[jj]!='*')
                {
                    return false;
                }
            }
                return true;
        }
    }
    // if(s[i-1]!=p[j-1])return false;

    if(s[i-1]==p[j-1] ||p[j-1]=='?')return dp[i][j]=func(dp,s,p,i-1,j-1);
    if(p[j-1]=='*') return dp[i][j]=func(dp,s,p,i-1,j) ||func(dp,s,p,i,j-1);
    return dp[i][j];
    
}
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        // return func(dp,s,p,s.size(),p.size());
        // for(int i=1;i<=n;i++)
        // {
        //     dp[i][0]=false;
        // }
        // for(int j=1;j<=m;j++)
        // {
        //     if(p[j-1]!='*')
        //     {
        //         dp[0][j]=false;
        //     }else
        //     {
        //         dp[0][j]=true;
        //     }
        // }
        // dp[0][0]=true;
        // for(int j=1;j<=m;j++){
        //     if(p[j-1]=='*')
        //     dp[0][j]=dp[0][j-1];
        // }
        vector<bool>prev(m+1,false);
        vector<bool>curr(m+1,false);
        prev[0]=true;
        for(int j=1;j<=m;j++){
            if(p[j-1]=='*')
            prev[j]=prev[j-1];
        }
        for(int i=1;i<=n;i++){
            fill(curr.begin(), curr.end(), false);
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] ||p[j-1]=='?')
                {
                    curr[j]=prev[j-1];
                }else if(p[j-1]=='*')
                {
                    curr[j]=prev[j]||curr[j-1];
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};