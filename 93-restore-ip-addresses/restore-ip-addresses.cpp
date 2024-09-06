class Solution {
public:
 bool helper(string & str)
 {
    if(str.size()>3 || str.size()<1 || (str[0]=='0' && str.size()>1)|| stoi(str)>255){
        return false;
    }
    return true;
 }
    void func(vector<string>& ans, string str, int index, string& s, int dot) {
        if (index >= s.size() || dot >= 4) {
            if (index == s.size() && dot == 4) {
                ans.push_back(str);
            }
            return;
        }
        for(int i=1;i<=3;i++)
        {
            if(index+i<=s.size())
            {
                string segment=s.substr(index,i);
                if (helper(segment)) {
                    // Add the segment and a dot if it's not the last segment
                    func(ans, str + segment + (dot < 3 ? "." : ""), index + i, s, dot + 1);
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.size()<4 && s.size()>12)return ans;
        string str;
        func(ans, "", 0, s, 0);
        return ans;
    }
};