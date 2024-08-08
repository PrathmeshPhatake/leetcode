class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int rowstart = 0;
        int rowend = n - 1;
        int colstart = 0;
        int colend = n - 1;
        vector<int> ans;
        int total = n * n;
        int count = 1;
        while (count <= total) {
            if (rowstart <= rowend) {
                for (int i = colstart; i <= colend; i++) {
                    matrix[rowstart][i]=count;
                    count++;
                }
                rowstart++;
            }
            if (colend >=colstart) {
                for (int i = rowstart; i <= rowend; i++) {
                    matrix[i][colend]=count;
                    count++;
                }
                colend--;
            }
            if (rowend >=rowstart) {
                for (int i = colend; i >= colstart; i--) {
                    matrix[rowend][i]=count;
                    count++;
                }
                rowend--;
            }
            if (colstart <= colend) {
                for (int i = rowend; i >= rowstart; i--) {
                   matrix[i][colstart]=count;
                    count++;
                }
                colstart++;
            }
        }
        return matrix;
    }
};