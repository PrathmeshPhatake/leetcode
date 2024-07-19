class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            int rowmin=INT_MAX;
            int colIndex;
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]<rowmin)
                {
                    rowmin=matrix[i][j];
                    colIndex=j;
                }
            }
            int colmax=INT_MIN;
            int rowindex;
            for(int k=0;k<n;k++)
            {
                if(matrix[k][colIndex]>colmax)
                {
                    colmax=matrix[k][colIndex];
                    rowindex=k;
                }
            }
            if(matrix[i][colIndex]==matrix[rowindex][colIndex])
            {
                return {matrix[i][colIndex]};
            }
        }
        return { };
    }
};