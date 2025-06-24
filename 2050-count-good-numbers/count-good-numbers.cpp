class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long e = (n + 1) / 2;   // even indices
        long long o = n / 2;         // odd  indices
        return int((modPow(5, e) * modPow(4, o)) % MOD);
    }
};
