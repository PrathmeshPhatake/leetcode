class Solution {
public:
long long dp[100001]; 
long long func(int i,vector<vector<int>>&questions)
{
    int n=questions.size();
    if(i>=n){return 0;}
    if(dp[i]!=-1) return dp[i];
    long long take=questions[i][0]+func(i+1+questions[i][1],questions);
    long long non_take=func(i+1,questions);
    return dp[i]=max(take,non_take);
}
    long long mostPoints(vector<vector<int>>& questions) {
    memset(dp, -1, sizeof(dp));  
    return func(0,questions);
    }
};