class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto  ch=*min_element(strs.begin(),strs.end());
        for(int i=0;i<ch.size();i++)
        {
            char k=ch[i];
            for(auto it:strs)
            {
                if(it[i]!=k)
                {
                    return ch.substr(0,i);
                }
            }
        }
        return ch;
    }
};