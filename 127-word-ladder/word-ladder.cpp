class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty())
        {
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==endWord) return step;
            // relcace ALL WORD
            for(int i=0;i<word.size();i++)
            {
                char original=word[i];
                // CHECK ALL CHAR AT EACH INDEX
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                //REPLCACE EACH WORD
                word[i]=original;
            }
        }
        return 0;
    }
};