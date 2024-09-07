class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        for (auto& h : health) {
            h = (h + power - 1) / power;
        }
        vector<int> indexes(n);
        for (int i = 0; i < n; ++i) {
            indexes[i] = i;
        }
        sort(indexes.begin(), indexes.end(), [&](int i, int j) {
            return health[i] * damage[j] < health[j] * damage[i];
        });
        long long res = 0;
        long long curTime = 0;
        for (const auto& i : indexes) {
            curTime += health[i];
            res += curTime * damage[i];
        }
        return res;
    }
};