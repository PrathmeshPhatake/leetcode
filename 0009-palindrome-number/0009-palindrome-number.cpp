class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        else
        {
            long long  reverse=0;
            long long temp=x;
            while(temp!=0)
            {
                int remainder=temp%10;
                reverse=reverse*10+remainder;
                temp=temp/10;
            }
            return (reverse==x);

        }

        
    }
};