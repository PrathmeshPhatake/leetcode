class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diff=0;
        int diff1=0;
        diff=abs(z-x);
        diff1=abs(z-y);
        if(diff<diff1)
        {
            return 1;
        }else if(diff>diff1)
        {
            return 2;
        }
        return 0;
    }
};