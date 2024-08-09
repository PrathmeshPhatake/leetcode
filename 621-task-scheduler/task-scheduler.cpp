class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int>mp;
        for(auto it:tasks)
        {
            mp[it]++;
        }
        int result=0;
        priority_queue<int>pq;
        for(auto it :mp)
        {
            pq.push(it.second);
        }
        while(!pq.empty())
        {
            vector<int>tmp;
            int time=0;
            for(int i=0;i<n+1;i++)
            {
                if(!pq.empty())
                {
                tmp.push_back(pq.top()-1);
                pq.pop();
                time++;
                }

            }
            for(auto it :tmp)
            {
                if(it>0)
                {pq.push(it);}
            }
            // in last we not need to add idle  
            result+=pq.empty()?time : n+1;
        }
        return result;
    }
};