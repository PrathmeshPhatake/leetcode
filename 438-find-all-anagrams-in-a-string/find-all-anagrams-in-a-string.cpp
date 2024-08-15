class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // optimized time  complexity
        int m = s.size();
        int n = p.size();
        vector<int> ans;
        for (int i = 0; i <= m - n; i++) {
            vector<int> temp(26, 0);
            bool flag = true;
            string str = s.substr(i, n);
            for (int j = 0; j < n; j++) {
                temp[p[j]-'a'] += 1;
                temp[ str[j]-'a'] -= 1;
            }
            for (int j = 0; j < 26; j++) {
                if (temp[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag)ans.push_back(i);
        }
        return ans;
    }
};