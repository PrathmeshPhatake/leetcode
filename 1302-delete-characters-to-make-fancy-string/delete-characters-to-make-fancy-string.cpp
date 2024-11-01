class Solution {
public:
    string makeFancyString(string s) {
        string str="";
        str.push_back(s[0]);
        int n=s.size();
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]==str.back())
            {
                count++;
                if(count<=2)str.push_back(s[i]);
            }
            else
            {
                count=1;
                str.push_back(s[i]);
            }
        }
        return str;
    }
};