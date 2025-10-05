class Solution {
public:
    bool func(vector<int>& weights, int days, int limit) {
        int count = 0;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] <= limit) {
                sum += weights[i];
            } else {
                count++;
                sum = weights[i];
            }
        }
        if (sum > 0)
            count++;
        if (count <= days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        int ans = 0;
        for (auto it : weights) {
            high += it;
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (func(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};