class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();        // number of rows
        int n = mat[0].size();     // number of columns
        vector<int> ans;
        ans.reserve(m * n);

        for (int d = 0; d < m + n - 1; d++) {
            vector<int> temp;
            int r = (d < n) ? 0 : d - n + 1;  // row start
            int c = (d < n) ? d : n - 1;      // col start

            // collect elements along this diagonal
            while (r < m && c >= 0) {
                temp.push_back(mat[r][c]);
                r++;
                c--;
            }

            // reverse every alternate diagonal
            if (d % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }

            ans.insert(ans.end(), temp.begin(), temp.end());
        }

        return ans;
    }
};
