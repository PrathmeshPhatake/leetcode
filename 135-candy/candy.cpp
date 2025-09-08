class Solution {
public:
    int candy(vector<int>& ratings) {
        int count=0;
        int n=ratings.size();
        vector<int>candy(n,0);
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                candy[i]=1;
            }else
            {
                if(ratings[i]>ratings[i-1])
                {
                    candy[i]=candy[i-1]+1;
                }else
                {
                    candy[i]=1;
                }
            }
        }
        int profit=0;
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                profit+=max(1,candy[i]);
            }else
            {
                if(ratings[i]>ratings[i+1])
                {
                    candy[i]=max(candy[i],candy[i+1]+1);
                    profit+=candy[i];
                }else
                {
                    candy[i]=max(candy[i],1);
                    profit+=candy[i];
                }
            }
        }
        return profit;
    }
};