class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& qu) {
        int n = s.size(), q = qu.size();
        vector<vector<int>> ans;  
        unordered_map<long long, pair<int, int>> map;


        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (map.count(0) == 0) 
                    map[0] = make_pair(i, i);
                continue;
            }
            long long num = 0;
            for (int j = i; j <= min(i + 32, n - 1); j++) { 
                num = (num << 1) + (s[j] - '0');
                if (map.count(num) == 0) 
                    map[num] = make_pair(i, j);
            }
        }

        for (int i = 0; i < q; i++) {
            int num = qu[i][0] ^ qu[i][1];  
            if (map.count(num)) 
                ans.push_back({map[num].first, map[num].second}); 
            else 
                ans.push_back({-1, -1});
        }

        return ans;
    }
};
