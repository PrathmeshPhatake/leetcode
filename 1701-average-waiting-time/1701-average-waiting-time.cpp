//time complexity:O(n)
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        int maxFirst=0;
        double  total=0;
        for(auto it:customers)
        {
            int first=it[0];
            int time=it[1];
            maxFirst=max(maxFirst,first);
            maxFirst+=time;
            total+=(maxFirst-first);
        }
        return total/n;
    }

};