class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str;
        int spaceIndex = 0; // Pointer to track the current space index
        int m = spaces.size();

        for (int i = 0; i < s.size(); i++) {
            // Check if current index matches the next space position
            if (spaceIndex < m && i == spaces[spaceIndex]) {
                str += " "; // Add a space
                spaceIndex++; // Move to the next space index
            }
            str += s[i]; // Add the current character
        }

        return str;
    }
};
