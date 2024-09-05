class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int rollsTotal = 0;
        for (int i = 0; i < m; i++) {
            rollsTotal += rolls[i];
        }
        int sum = mean * (m + n) - rollsTotal;
        if (sum < n || sum > 6 * n) return {}; 
        
        vector<int> missing(n,sum/n);
        int rem=sum%n;
        // first intilize value of all then  add rem in all valuein spliting 
        for(int i=0;i<rem;i++)
        {
            missing[i]++;
        }
        return missing;
    }
};