class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        int n=words.size();
        for(int i=0;i<n;i++){
            string str=words[i];
            for(auto it:words)
            {
                if(it.find(str)!=string::npos && str!=it)
                {
                    ans.push_back(str);
                    break;
                }
            }
        }
        return ans;
    }
};