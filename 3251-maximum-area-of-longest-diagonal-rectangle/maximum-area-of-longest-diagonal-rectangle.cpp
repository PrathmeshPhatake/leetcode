class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        long long maxDiagSq = -1; // store diagonal squared
        int maxArea = -1;

        for (int i = 0; i < n; i++) {
            int a = dimensions[i][0];
            int b = dimensions[i][1];
            long long diagSq = 1LL * a * a + 1LL * b * b; // avoid overflow
            int area = a * b;

            if (diagSq > maxDiagSq || (diagSq == maxDiagSq && area > maxArea)) {
                maxDiagSq = diagSq;
                maxArea = area;
            }
        }
        return maxArea;
    }
};
