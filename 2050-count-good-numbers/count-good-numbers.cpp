class Solution {
    long long power(long long base,long expo,int mod)
    {
        long long result=1;
        while(expo>0)
        {
            if(expo%2==1)
            {
                result=(result*base)%mod;
            }
            base=(base*base)%mod;
            expo/=2;
        }
        return result;
    }
public:
    int countGoodNumbers(long long n) {
        int mod = 1e9 + 7;
        
        // Calculate the number of even and odd positions
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        

        
        long long result = power(5, even, mod) * power(4, odd, mod) % mod;

        return static_cast<int>(result);
    }
};
    // 