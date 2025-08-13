class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        while(n>1)
        {
            if(n%3!=0) return false;
            n=static_cast<int>(round(n/3.0));
        }
        return  true;
    }
};