class Solution {
public:
int func(vector<vector<int>>& triangle,vector<vector<int>>& dp,int row,int col)
{
    int m= triangle.size();
    int n=triangle[0].size();
    // base case 
    if(row==m-1)
    {
        return triangle[row][col];
    }
    // check this is already persent or not 
    if(dp[row][col]!=-1) return dp[row][col];
    int temp=INT_MAX;
    // going next row with col and col+1
    for(int i=col;i<=col+1 ;i++)
    {
        temp=min(temp,triangle[row][col]+func(triangle,dp,row+1,i));
    }
    return dp[row][col]=temp;
}
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp;
        // we want this type of dp array 
        for(auto it:triangle)
        {
            dp.push_back(vector<int>(it.size(),-1));
        }
        return func(triangle,dp,0,0);


    }
};