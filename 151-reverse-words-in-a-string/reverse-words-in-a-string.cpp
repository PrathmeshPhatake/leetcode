class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        vector<string>ans;
        while(iss>>word)
        {
            ans.push_back(word);
        }
        string str;
        for(int i=ans.size()-1;i>=0;i--)
        {
            if(i!=0){str+=ans[i]+" ";}
            else
            {
                str+=ans[i];
            }
        }
        return str;
    }
};