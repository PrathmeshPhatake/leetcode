class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            string temp="";
            for(int j=0;j<n;j++)
            {
                temp+=s[(j+i+n)%n];
            }
            if(temp==goal) return true;
        }
        return false;
    }
};