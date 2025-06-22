class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size();
        int mod=n%k;
        if(mod!=0)
        {
            s.append(k-mod,fill);
        }
        
        vector<string>res;
        n=s.size();
        for(int i=0;i<n;i+=k)
        {
            res.push_back(s.substr(i,k));
        }
        return res;
    }
};