class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string str;
        int i=0;
        while(ss>>str)
        {
            i++;
            if(str.substr(0,searchWord.size())==searchWord)
            {
                return i;
            }
        }
        return -1;
    }
};