class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0); // Difference array
        
        // Process each shift
        for (auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            // Forward shift
            if (direction == 1) {
                diff[start] += 1;
                diff[end + 1] -= 1;
            }
            // Backward shift
            else {
                diff[start] -= 1;
                diff[end + 1] += 1;
            }
        }

        // Compute cumulative shifts
        int shift = 0;
        for (int i = 0; i < n; i++) {
            shift += diff[i];
            shift = (shift % 26 + 26) % 26; // Normalize shift to [0, 25]
            s[i] = (s[i] - 'a' + shift) % 26 + 'a'; // Apply shift
        }

        return s;
    }
};
