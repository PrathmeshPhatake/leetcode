class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int gp=0;
        int sp=0;
        int count=0;
        while(gp<g.size() && sp<s.size())
        {
            if(s[sp]>=g[gp])
            {
                gp++;
                count++;
            }
            sp++;
        }
        return count;
    }
};