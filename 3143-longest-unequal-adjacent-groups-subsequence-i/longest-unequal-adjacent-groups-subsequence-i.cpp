class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        int order = -1;
        for (int i = 0; i < groups.size(); i++) {
            if (groups[i] != order) {
                order = groups[i];
                res.push_back(words[i]);
            }
        }
        return res;
    }
};