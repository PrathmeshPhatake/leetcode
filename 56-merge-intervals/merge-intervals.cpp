class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end(),[](const vector<int>&a, const vector<int>&b){
        return a[0]<b[0];
       });
       vector<vector<int>>ans;
       int ptail=INT_MIN;
       int phead=INT_MAX;
       for(auto it:intervals)
       {
          if(ptail>=it[0])
          {
            ans.pop_back();
            ptail=max(ptail,it[1]);
            ans.push_back({phead,ptail});
          }else
          {
            ptail=it[1];
            phead=it[0];
            ans.push_back({it[0],it[1]});
          }
       }
       return ans;
    }
};