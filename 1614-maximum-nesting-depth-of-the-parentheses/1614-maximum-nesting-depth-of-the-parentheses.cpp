class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int maximum=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                cnt++;
            }
            if(s[i]==')')
            {
                maximum=max(maximum,cnt);
                cnt--;
            }
        }
        return maximum;
        
    }
};