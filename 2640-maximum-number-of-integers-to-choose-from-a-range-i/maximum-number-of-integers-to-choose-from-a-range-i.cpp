class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>banned_set(banned.begin(),banned.end());
        int count=0;
        int currentSum=0;
        for(int i=1;i<=n;i++)
        {
            if(banned_set.find(i)==banned_set.end())
            {
                if(currentSum+i >maxSum)
                {
                   break;
                }
                currentSum+=i;
                count++;
            }
        }
        return count;
    }
};