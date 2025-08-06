class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            for( j;j<m;j++)
            {
                if(s[j]>=g[i])
                {
                    s[j]=-1;
                    count++;
                    break;
                }
            }

        }
        return count;
    }
};