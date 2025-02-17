class Solution {
public:
    long long  calculateHours(vector<int>& piles, int mid) {
        long long  totalHours = 0;
        for (int it : piles) {
            totalHours += ceil((double)it / mid);
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = r;  // Max speed is the upper bound

        while (l <= r) {
            int mid = l + (r - l) / 2;  // ✅ Prevents overflow

            long long total = calculateHours(piles, mid);
            if (total <= h) {
                ans = mid;  // Store possible answer
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};