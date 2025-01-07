class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        vector<string>ans;
        for(auto it:words)
        {
            for(auto str:words)
            {
                if(str.find(it)!=string::npos && it!=str)
                {
                    ans.push_back(it);
                    break;
                }
            }
        }
        return ans;
    }
};