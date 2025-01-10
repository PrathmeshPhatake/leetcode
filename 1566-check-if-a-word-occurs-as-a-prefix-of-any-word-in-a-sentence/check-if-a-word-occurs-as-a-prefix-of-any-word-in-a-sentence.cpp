class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int i=1;
        int count=-1;
        while(ss>>word)
        {
            if(word.substr(0,searchWord.size())==searchWord)
            {
                count=i;
                break;
            }
            i++;
        }
        return count;
    }
};