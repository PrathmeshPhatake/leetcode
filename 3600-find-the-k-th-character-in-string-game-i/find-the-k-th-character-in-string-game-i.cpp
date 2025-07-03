class Solution {
public:
    char kthCharacter(int k) {
        string str="a";
        while(str.size()<k)
        {
            int n=str.size();
            for(int i=0;i<n;i++)
            {
                char ch=(str[i]-'a'+1)%26+'a';
                str.push_back(ch);
            }
        }
        return str[k-1];
    }
};