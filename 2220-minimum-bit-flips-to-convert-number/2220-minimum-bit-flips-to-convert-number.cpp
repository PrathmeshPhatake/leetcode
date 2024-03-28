class Solution {
public:
    int minBitFlips(int start, int goal) {
        //num store the number which  store a bit
       int num=start^goal;

       //counting the number of bit 
       int cnt=0;
       while(num!=0)
       {
          num=num&(num-1);
          cnt++;
       } 
       return cnt;
    }
};