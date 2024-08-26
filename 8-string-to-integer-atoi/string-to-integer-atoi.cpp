class Solution {
public:
    int myAtoi(string s) {
        // space handling 
        int sign=1;
        int ans=0;
        int i=0;
        while(i<s.size() && isspace(s[i]))
        {
            i++;
        }
        bool signSeen=false;
        // Step 2: Handle optional sign
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            signSeen = true;
            i++;
        }

        // Step 3: Check for multiple signs
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            return 0;
        }
        // get integer
        while(i<s.size()&& isdigit(s[i]))
        {
            int digit=s[i]-'0';
            if(ans>(INT_MAX-digit)/10)
            {
                return (sign==1)?INT_MAX:INT_MIN;
            }
            ans=ans*10 +digit;
            i++;
        }
        return ans*sign;
    }
};