class Solution {
public:
vector<vector<int>>dp; //-1=unvi
bool func(int i,int cnt,string s)
{
    if(cnt<0) return false;
    int n=s.length();
    if(i==n) return cnt==0;
    if(dp[i][cnt]!=-1) return dp[i][cnt];
    bool ans=false;
    if(s[i]=='('){
        ans= func(i+1,cnt+1,s);
    }else if(s[i]==')')
    {
        ans= func(i+1,cnt-1,s);
    }
    else
    {
        ans=func(i+1,cnt+1,s) || func(i+1,cnt-1,s) || func(i+1,cnt,s);
    }
    return dp[i][cnt]=ans;
}
    bool checkValidString(string s) {
        int n=s.length();
        dp.assign(n+1,vector<int>(n+1,-1));
        return func(0,0,s);
    }
};