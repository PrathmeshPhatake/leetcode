class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int count = 0;
        int maxi = 0;
        int sum = 0;
        int lsum = 0;
        int rsum = 0;
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }
        maxi = lsum;
        int right = n - 1;
        for (int i = k - 1; i >= 0; i--) {
            lsum -= cardPoints[i];
            rsum += cardPoints[right];
            maxi = max(maxi, (lsum + rsum));
            right--;
        }
        return maxi;
    }
};