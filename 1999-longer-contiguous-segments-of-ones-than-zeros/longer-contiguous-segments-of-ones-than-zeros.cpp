class Solution {
public:
    bool checkZeroOnes(string s) {
        int maxO=INT_MIN;
        int maxl=INT_MIN;
        int zero=0;
        int one=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                one++;
                zero=0;

            }
            else
            {
                zero++;
                one=0;
            }
            maxO=max(maxO,zero);
            maxl=max(maxl,one);

        }
        if(maxl>maxO) return true;
        return false;
        
        
    }
};