class Solution {
public:
    // Helper function to check if a string starts and ends with a vowel
    bool isVowelString(const string& str) {
        char first = str[0];
        char last = str.back();
        return (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') &&
               (last == 'a' || last == 'e' || last == 'i' || last == 'o' || last == 'u');
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 1, 0);

        // Build the prefix sum array
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + (isVowelString(words[i]) ? 1 : 0);
        }

        vector<int> ans;
        // Process each query
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            ans.push_back(prefix[r + 1] - prefix[l]);
        }

        return ans;
    }
};
