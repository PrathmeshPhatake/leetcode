class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int nhead = newInterval[0];
        int ntail = newInterval[1];
        vector<vector<int>> ans;
        int n = intervals.size();
        bool inserted = false;

        for (int i = 0; i < n; i++) {
            int head = intervals[i][0];
            int tail = intervals[i][1];

            // Case 1: No overlap, interval before newInterval
            if (tail < nhead) {
                ans.push_back({head, tail});
            }
            // Case 2: No overlap, interval after newInterval
            else if (head > ntail) {
                if (!inserted) {
                    ans.push_back({nhead, ntail});
                    inserted = true;
                }
                ans.push_back({head, tail});
            }
            // Case 3: Overlap — merge
            else {
                nhead = min(nhead, head);
                ntail = max(ntail, tail);
            }
        }

        // If newInterval goes at the end
        if (!inserted) {
            ans.push_back({nhead, ntail});
        }

        return ans;
    }
};
