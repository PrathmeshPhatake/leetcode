class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        
        int si=0;
        int gi=0;
        int k=0;
        while(si<s.size() && gi<g.size())
        {
            if(s[si]>=g[gi])
            {
                k++;
                si++;
                gi++;
            }
            else
            {
                si++;
            }

            
        }
        return k;
    }
};