#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int dp[31][1001];
    const long long mod=1e9+7;
    int n, k;
    int f(int i, int t){
        if (i==0 && t==0) return 1;//base case
        if (i<=0 || t<=0) return 0;
        if (dp[i][t]!=-1) return dp[i][t];
        long long ans=0;
        for(int p=1; p<=k; p++)
            ans=(ans+f(i-1, t-p))%mod;
        return dp[i][t]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        this->n=n;
        this->k=k;
        fill(&dp[0][0], &dp[0][0]+31*1001, -1);
        return f(n, target);
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();