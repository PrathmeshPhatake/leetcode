class Solution {
public:
    int getLucky(string s, int k) {
        int n=s.size();
        string str;
        for(int i=0;i<n;i++)
        {
            str+=to_string(s[i]-'a'+1);
        }
        while(k--)
        {
            int temp=0;
            for(int i=0;i<str.size();i++)
            {
                temp+=str[i]-'0';
            }
            str.clear();

            str=to_string(temp);
        }
        return stoi(str);
    }
};