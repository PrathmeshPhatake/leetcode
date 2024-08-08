class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int rowstart = 0;
        int rowend = row - 1;
        int colstart = 0;
        int colend = col - 1;
        vector<int> ans;
        int total = row * col;
        int count = 0;
        while (count < total) {
            if (rowstart <= rowend) {
                for (int i = colstart; i <= colend; i++) {
                    ans.push_back(matrix[rowstart][i]);
                    count++;
                }
                rowstart++;
            }
            if (colend >=colstart) {
                for (int i = rowstart; i <= rowend; i++) {
                    ans.push_back(matrix[i][colend]);
                    count++;
                }
                colend--;
            }
            if (rowend >=rowstart) {
                for (int i = colend; i >= colstart; i--) {
                    ans.push_back(matrix[rowend][i]);
                    count++;
                }
                rowend--;
            }
            if (colstart <= colend) {
                for (int i = rowend; i >= rowstart; i--) {
                    ans.push_back(matrix[i][colstart]);
                    count++;
                }
                colstart++;
            }
        }
        return ans;
    }
};