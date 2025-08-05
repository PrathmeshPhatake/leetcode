class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int m=baskets.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(baskets[j]>=fruits[i])
                {
                    baskets[j]=-1;
                    break;
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++)
        {
            if(baskets[i]!=-1)
            {
               count++; 
            }

        }
        return count;
    }
};