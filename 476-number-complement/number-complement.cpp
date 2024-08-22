class Solution {
public:
    int findComplement(int num) {
       int mask=0;
       int m=num;
       while(m!=0)
       {
        mask=(mask<<1)|1;
        m=m>>1;
       }
       return (~num & mask);
    }
};