class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            string it=words[i];
            for(int j=i+1;j<n;j++){
                string str=words[j];
                if(str.size()<it.size())
                {
                    continue;
                }
                string prefix=str.substr(0,it.size());
                string suffix=str.substr(str.size()-it.size(),it.size());
                if(prefix==it && suffix==it  )
                {
                    count++;
                }
            }
        }
            return count;
    }
};