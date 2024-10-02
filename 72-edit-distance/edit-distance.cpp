class Solution {
public:
int  counting(vector<vector<int>>&dp,string s,string t,int i,int j)
{
    int n=s.size();
    int m=t.size();

    if(i>=n || j>=m)
    {
        if(j>=m)
        {
            
            return n-i;
        }
        else
        {
   
            return m-j;
        }
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int mini=INT_MAX;
    if(s[i]==t[j])
    {
        mini=counting(dp,s,t,i+1,j+1);
    }
    else
    {
       
        mini=1+min({counting(dp,s,t,i+1,j+1), counting(dp,s,t,i+1,j),counting(dp,s,t,i,j+1)});
    }
    return dp[i][j]=mini;

}
    int minDistance(string word1, string word2) {
        if(word1.empty())return word2.size();
        if(word2.empty())return word1.size();
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return counting(dp,word1,word2,0,0);
        
    }
};