class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        //sort and reverse arrary and put in queue
        sort(happiness.begin(),happiness.end());
        reverse(happiness.begin(),happiness.end());
        queue<int> q;
        for( int j:happiness)
        {
            q.push(j);
        }
        //nwe get max value and decrease value by one remeaning value  upto  
        // the k
        long long  store=0;
        int totalsum=0;
        int turn=0;
        for( int i=0;i<k;i++)
        {
            totalsum=max(q.front()-turn,0);
            store=store+totalsum;
            turn++;
            q.pop();
        }
        return store;

    }
};