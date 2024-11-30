class Solution {
public:
int func(vector<vector<int>>dp,string text1, string text2,int i,int j)
{
    int m=text1.size();
    int n=text2.size();
    if(i==m || j==n)
    {
        return 0;

    }
    if(dp[i][j]!=-1)return dp[i][j];
    // if(i==m || j==n)return;
    if(text1[i]==text2[j]){
        dp[i][j]=1+func(dp,text1,text2,i+1,j+1);
    }
    else
    {
        dp[i][j]=max(func(dp,text1,text2,i,j+1),func(dp,text1,text2,i+1,j));
    }
    return dp[i][j];
    
}
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        // return func(dp,text1,text2,0,0);
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];

                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
       
    }
};