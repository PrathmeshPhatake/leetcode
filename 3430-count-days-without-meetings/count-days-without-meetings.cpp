class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int count=0;
        int prev_end=0;
        for(auto it:meetings)
        {
            int start=it[0];
            int end=it[1];
            if(start>prev_end)
            {
                count+=(end-start+1);
                
            }
            else if(end>prev_end)
            {
                count+=(end-prev_end);
            }
            
            prev_end = max(prev_end, end);
        }
        return days-count;
    }
};