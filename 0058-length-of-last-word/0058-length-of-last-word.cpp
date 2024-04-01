class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        int n=s.size()-1;
        //REMOVE LAST SPACE OF STRING
        while(s[n]==' ')
        {
            n--;
        }
        s.erase(n+1);
        //COUNT WORD SIZE
        for(int i=n;i>=0;i--)
        {
            if(s[i]==' ')
            {
                break;
            }
            cnt++;
        }
        return cnt;
        
    }
};