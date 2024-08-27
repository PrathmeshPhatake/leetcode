class Solution {
public:
    int countGoodNumbers(long long n) {
        int mod = 1e9 + 7;
        
        // Calculate the number of even and odd positions
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        // Helper function to calculate (base^exp) % mod
        auto modPow = [](long long base, long long exp, int mod) -> long long {
            long long result = 1;
            while (exp > 0) {
                if (exp % 2 == 1) {
                    result = (result * base) % mod;
                }
                base = (base * base) % mod;
                exp /= 2;
            }
            return result;
        };

        // Calculate 5^even % mod and 4^odd % mod
        long long result = modPow(5, even, mod) * modPow(4, odd, mod) % mod;

        return static_cast<int>(result);
    }
};
    // 