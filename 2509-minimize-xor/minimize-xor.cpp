class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bitCount = __builtin_popcount(num2); // Count set bits in num2
        int result = 0;

        // Set bits in result to minimize XOR
        for (int i = 31; i >= 0 && bitCount > 0; --i) {
            if (num1 & (1 << i)) {
                result |= (1 << i);
                bitCount--;
            }
        }

        // If there are still bits to set, set them in the lowest positions
        for (int i = 0; i < 32 && bitCount > 0; ++i) {
            if (!(result & (1 << i))) {
                result |= (1 << i);
                bitCount--;
            }
        }

        return result;
    }
};
