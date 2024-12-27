class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_value = values[0];
        int maxi = 0;
        
        for (int j = 1; j < values.size(); ++j) {
            maxi = max(maxi, max_value + values[j] - j);
            max_value = max(max_value, values[j] + j);
        }
        
        return maxi;
    }
};
