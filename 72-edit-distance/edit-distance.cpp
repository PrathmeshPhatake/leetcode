class Solution {
public:
    int func(vector<vector<int>>& dp, string s1, string s2, int i, int j) {
        if (i ==0)
            return j ;
        if (j ==0)
            return i ;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i-1] == s2[j-1])
            return dp[i][j] = 0 + func(dp, s1, s2, i - 1, j - 1);
        // all operation on s1
        // new insert  (if insert it match with s2 so i-1)
        // replace  (replace with mathc var then i-1,j-1)
        // delete  (if delete not mathc with s2 )
        int maxi = 0;
        if (s1[i-1] != s2[j-1]) {
            return maxi = 1 + min({func(dp, s1, s2, i, j - 1),
                                   func(dp, s1, s2, i - 1, j - 1),
                                   func(dp, s1, s2, i - 1, j)});
        }
        return dp[i][j]=maxi;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        // return func(dp, word1, word2, n , m );
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=i;

        }
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=i;

        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }else
                {
                    dp[i][j]=1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                }
            }
        }
        return dp[n][m];

    }
};