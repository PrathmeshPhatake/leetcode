class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0;
        int j=0;
        while(i<str1.size() && j<str2.size())
        {
            char current=str1[i];
            char increment=(str1[i]-'a'+1)%26 +'a';
            if(str2[j]==current || str2[j]==increment)
            {
                j++;
            }
            i++;
        }
        return j==str2.size();
    }
};