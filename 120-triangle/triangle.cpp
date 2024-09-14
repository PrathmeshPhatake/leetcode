class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
         vector<vector<int>>dp;
        // we want this type of dp array 
        for(auto it:triangle)
        {
            dp.push_back(vector<int>(it.size(),INT_MAX));
        }
        // base case 
        dp[0][0]=triangle[0][0];
        int m=triangle.size();
        for(int i=1;i<m;i++)
        {
            int n=triangle[i].size();
            for(int j=0;j<n;j++)
            {
                if(j<triangle[i-1].size())
                {
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+triangle[i][j]);
                }
                if( j-1>=0)
                {
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]+triangle[i][j]);
                }
            }
        }
        int temp=INT_MAX;
        for(int i=0;i<triangle[m-1].size();i++)
        {
            temp=min(temp,dp[m-1][i]);
        }
        return temp;
    }
};