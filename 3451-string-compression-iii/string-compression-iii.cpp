class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int n=word.size();
        for(int i=0;i<n;)
        {
            int k=i;
            int count=0;
            while(i<n && word[i]==word[k] && count<9)
            {
                k++;
                count++;
            }
            ans.push_back('0'+count);
            ans.push_back(word[i]);
            i=k;
        }
        return ans;
    }
};