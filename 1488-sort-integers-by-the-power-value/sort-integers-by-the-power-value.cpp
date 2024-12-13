class Solution {
public:
int power(int num)
{
    int count=0;
    while(num!=1)
    {
        if(num%2==0)
        {
            num=num/2;
        }
        else
        {
            num=(3*num)+1;
        }
        count++;
    }
    return count;
}
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        k--;
        for(int i=lo;i<=hi;i++)
        {
            pq.push({power(i),i});
        }
        while(k--)
        {
            pq.pop();
        }
        return pq.top().second;
    }
};