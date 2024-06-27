class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int>mp;
        for(int i=0;i<edges.size();i++)
        {
            for(int j=0;j<edges[i].size();j++)
            {
                mp[edges[i][j]]++;
            }

        }
        for(auto num:mp)
        {
            if(num.second==edges.size())
            {
                return num.first;
            }
        }
        return -1;
    }
};