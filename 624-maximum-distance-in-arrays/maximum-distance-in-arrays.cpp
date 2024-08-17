class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int dist=0;
        int mini=arrays[0][0];
        int maxi=arrays[0].back();
        for(int  i=1;i<arrays.size();i++)
        {
            dist=max(max(dist,(maxi-arrays[i][0])),max(dist,(arrays[i].back()-mini)));

            mini=min(mini,arrays[i][0]);
            maxi=max(maxi,arrays[i].back());

        }
        return dist;
    }
};