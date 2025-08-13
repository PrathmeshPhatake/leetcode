class Solution {
public:
    bool isPowerOfThree(int n) {
        int i=0;
        while(i<n)
        {
            if(pow(3,i)==n){
                return true;
            }
            else if(pow(3,i)>n)
            {
                return false;
            }
            i++;
        }
        return false;
    }
};