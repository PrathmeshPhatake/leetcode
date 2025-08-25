class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n)
            return false;
        unordered_map<char, int> map;
        for (int i = 0; i < n; i++) {
            map[s[i]]++;
        }
        for (int i = 0; i < m; i++) {
            map[t[i]]--;
        }

        for (auto it : map) {
            if (it.second != 0)
                return false;
        }
        return true;
    }
};