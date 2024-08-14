class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;
        int n=s.size();
        int k=0;
        while(k<=n)
        {
            string str=s;
            for(int i=0;i<n;i++)
            {
                str[(i+k)%n]=s[i];
            }
            if(str==goal)
            {
                return true;
            
            }
            k++;   
        }
        return false;
    }
};