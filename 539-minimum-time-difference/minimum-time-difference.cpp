class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        vector<int>minutes(n);
        for(int i=0;i<n;i++)
        {
            int h=stoi(timePoints[i].substr(0,2));
            int m=stoi(timePoints[i].substr(3));
            minutes[i]=h*60+m;
        }
        sort(minutes.begin(),minutes.end());
        int minDiff=INT_MAX;
        for(int i=0;i<minutes.size()-1;++i)
        {
            minDiff=min(minDiff,minutes[i+1]-minutes[i]);
        }
        minDiff=min(minDiff,24*60-minutes.back()+minutes.front());
        return minDiff;
    }
};