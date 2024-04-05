class Solution {
public:
    string makeGood(string s) {
        
        string makegood="";
        stack<char>sq;
        sq.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            
            if (!sq.empty() && tolower(s[i]) == tolower(sq.top()) && s[i] != sq.top()) {
                sq.pop();
            } else {
                sq.push(s[i]);
            }
        }
         while(!sq.empty())
         {
            makegood.push_back(sq.top());
            sq.pop();
            
         }
         reverse(makegood.begin(),makegood.end());
        return makegood;
    }
};