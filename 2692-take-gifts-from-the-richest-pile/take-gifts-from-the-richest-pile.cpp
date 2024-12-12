class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum=0;
        int n=gifts.size();
        for(int i=0;i<k;i++)
        {
            int index=-1;
            int maxi=INT_MIN;
            for(int j=0;j<n;j++)
            {
                if(maxi<gifts[j])
                {
                    index=j;
                    maxi=gifts[j];
                }
            }
            gifts[index]=sqrt(maxi);
        }
       
        for(auto it:gifts)sum+=it;
        return sum;
    }
};