class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        for(char ch='a';ch<='z';ch++)
        {
            int mincount=INT_MAX;
            for(string word:words)
            {
                int count =0;
                for(char cha:word)
                {
                    if(cha==ch)
                    {
                        count++;
                    }
                }

                //min  count of given char of all words
                mincount=min(mincount,count);
            }
            for(int i=0;i<mincount;i++)
            {
                ans.push_back(string(1,ch));
            }
        }
        return ans;
    }
};