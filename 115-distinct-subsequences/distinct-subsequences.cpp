class Solution {
    int   counting(vector<vector<int>>&dp,int i,int j,string& s,string& t)
    {
        if(i<0 || j<0 )
        {
            if(j<0)
            {
                return 1;
            }
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int left=0;
        int right=0;
        if(s[i]==t[j])
        {
            left=counting(dp,i-1,j-1,s,t);
            right=counting(dp,i-1,j,s,t);
        }
        else
        {
            left=counting(dp,i-1,j,s,t);
        }
        return dp[i][j]=left+right;
    }
public:
    int numDistinct(string s, string t) {
        
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return counting(dp,n-1,m-1,s,t);
        
    }
};