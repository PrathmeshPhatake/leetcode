// sum  of prime factor of given number 
class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        int sum=0;
        int factor=2;
        while(n>1)
        {
            while(n%factor==0)
            {
                sum+=factor;
                n/=factor;
            }
            factor++;
        }
        return sum;
    }
};