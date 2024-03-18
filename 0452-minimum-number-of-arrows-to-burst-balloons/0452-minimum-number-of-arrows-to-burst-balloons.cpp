class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp=[](vector<int>&a ,vector<int>& b)
        {
            return a[1]<b[1];

        };
        sort(points.begin(),points.end(),cmp);
        int arrowsps=points[0][1],arrowshot=1;
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]<=arrowsps)
            continue;

            arrowsps =points[i][1];
            arrowsps=points[i][1];
            arrowshot++;
        }
        return arrowshot;
    }
};