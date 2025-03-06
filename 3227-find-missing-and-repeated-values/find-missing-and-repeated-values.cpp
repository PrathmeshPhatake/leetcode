class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        set<int> st;
        int n = grid.size()*grid.size();
        int a = 0;
        int b = 0;
        int sum = 0;
        for (auto row : grid) {
            for (auto it : row) {
                if (st.find(it) != st.end()) {
                    a = it;

                } else {
                    st.insert(it);
                }
                sum += it;
            }
        }
        int total = n * (n + 1) / 2;
        return {a, total - (sum-a)};
    }
};