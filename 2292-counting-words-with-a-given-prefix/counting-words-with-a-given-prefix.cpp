class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            string str=words[i];
            if(str.substr(0,pref.size())==pref)
            count++;
        }
        return count;
    }
};