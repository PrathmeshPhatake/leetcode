class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count=0;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            string str=words[i];
            int size=str.size();
            string temp=s.substr(0,size);
            if(str==temp)
            {
                count++;
            }
        }
        return count;
    }
};