class Solution {
public:
    int nthUglyNumber(int n) {
        // priority queue
        priority_queue<long,vector<long>,greater<long>>pq;
        unordered_set<long>set;
        pq.push(1);
        set.insert(1);
        long num=1;
        for(int i=0;i<n;i++)
        {
             num=pq.top();
            pq.pop();
            if(set.find(num*2)==set.end())
            {
                pq.push(num*2);
                set.insert(num*2);
            }
            if(set.find(num*3)==set.end())
            {
                pq.push(num*3);
                set.insert(num*3);
            }
            if(set.find(num*5)==set.end())
            {
                pq.push(num*5);
                set.insert(num*5);
            }
            
        }
        return num;
    }
};