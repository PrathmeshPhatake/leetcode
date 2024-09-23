class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       // base case
       for(int i=0;i<n;i++) dp[i][0]=0;
       for(int i=0;i<m;i++) dp[0][i]=0;
        for(int id1=1;id1<=n;id1++)
        {
            for(int id2=1;id2<=m;id2++)
            {
                if(text1[id1-1]==text2[id2-1])
                {
                    dp[id1][id2]=1+dp[id1-1][id2-1];
                }
                else
                {
                    dp[id1][id2]=max(dp[id1][id2-1],dp[id1-1][id2]);
                }
            }
        }
        return dp[n][m];
    }
};