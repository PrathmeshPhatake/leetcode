// we memoized the steps
//  when we at 3 then we jump on 4,5 that
// if we now at 3  we know counting of to reach 5 then we not need to check  at 4 adn 5 
class Solution {
    int climb(int n,int stairs,vector<int>&dp)
    {
        if(stairs>n)return 0;
        if(stairs==n)return 1;
        if(dp[stairs]!=-1)return dp[stairs];
        return dp[stairs]=climb(n,stairs+1,dp)+climb(n,stairs+2,dp);
        return dp[stairs];
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n,-1);
        return climb(n,0,dp);
        
    }
};