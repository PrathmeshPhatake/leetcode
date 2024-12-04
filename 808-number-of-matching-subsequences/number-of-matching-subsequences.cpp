class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // Step 1: Preprocess `s` into a map of character indices
        unordered_map<char, vector<int>> charIndices;
        for (int i = 0; i < s.size(); i++) {
            charIndices[s[i]].push_back(i);
        }

        // Step 2: Check each word if it is a subsequence
        int count = 0;
        for (auto& word : words) {
            int lastIndex = -1; // Tracks the last index matched in `s`
            bool isSubsequence = true;

            for (char c : word) {
                if (charIndices.find(c) == charIndices.end()) {
                    isSubsequence = false;
                    break;
                }

                // Find the next valid position using binary search
                auto it = upper_bound(charIndices[c].begin(), charIndices[c].end(), lastIndex);
                if (it == charIndices[c].end()) {
                    isSubsequence = false;
                    break;
                }
                lastIndex = *it; // Update the last matched index
            }

            if (isSubsequence) {
                count++;
            }
        }

        return count;
    }
};
