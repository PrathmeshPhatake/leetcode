class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size();
        int j = 0;
        vector<int> visited(n, 0);
        long long res = 0;

        while (j >= 0 && j < n) {
            if (visited[j] == 1) {
                return res;
            }

            visited[j] = 1;

            if (instructions[j] == "add") {
                res += values[j];
                j++;  // move to next instruction
            } else if (instructions[j] == "jump") {
                j += values[j];  // relative jump
            } else {
                // Optional: handle invalid instruction
                break;
            }
        }

        return res;
    }
};
