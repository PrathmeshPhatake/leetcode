class Solution {
public:
    int addDigits(int num) {
        while(num>9)
        {
            int temp=0;
            while(num>0)
            {
                int rem=num%10;
                temp+=rem;
                num/=10;
            }
            num=temp;
        }
        return num;
    }
};