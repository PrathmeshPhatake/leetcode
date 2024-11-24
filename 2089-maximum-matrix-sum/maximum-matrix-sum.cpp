class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long  sum=0;
        int mini=INT_MAX;
        int negative=0;
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum+=abs(matrix[i][j]);
                mini=min(abs(matrix[i][j]),mini);
                if(matrix[i][j]<0)
                {
                    
                    negative++;
                }
            }
        }
        if(negative%2!=0)return sum-(2*mini);

        return sum;
    }
};