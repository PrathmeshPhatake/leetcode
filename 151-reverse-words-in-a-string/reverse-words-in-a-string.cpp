class Solution {
public:
    string reverseWords(string s) {
        istringstream stream(s);
        string word;
        vector<string>ans;
        
        while(stream >> word)
        {
            ans.push_back(word);
        }
        reverse(ans.begin(),ans.end());
        string str;
        for(int i=0;i<ans.size();i++)
        {
            str+=ans[i]+" ";
        }
         str.pop_back();
         return str;
    }
};