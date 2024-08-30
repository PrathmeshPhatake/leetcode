class Solution {
public:
void paranethes(int open,int close,vector<string>&ans,string str)
{
    if(open==0 && close==0)
    {
        ans.push_back(str);
    }
    if(open>0)
    {
        str.push_back('(');
        paranethes(open-1,close,ans,str);
        str.pop_back();

    }
    if(close>open)
    {
        str.push_back(')');
        paranethes(open,close-1,ans,str);
        str.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        string str;
        vector<string>ans;
        paranethes(n,n,ans,str);
        return ans;
    }
};