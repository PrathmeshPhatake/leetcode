class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        bool sign=true;
        if(dividend>=0 & divisor<0) sign=false;
        if(dividend<0 && divisor>=0) sign=false;
        //if these int value in not in range
        long n=abs(dividend);
        long d=abs(divisor);
        int quoient=0;
        
        while(n>=d)
        {
            int  cnt=0;
            while(n>=(d<<(cnt+1)))
            {
                cnt+=1;
            }
            quoient+=(1<<cnt);// we add in 2`s power 
            n-=(d<<cnt);
        }
        if(quoient==(1<<31) && sign)return INT_MAX;
        if(quoient==(1<<31) && !sign)return INT_MIN;
        //if +ve : -ve
         return sign ? quoient:(-1*quoient);
    }
};