class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++)
        {
            string str=to_string(i);
            int left=0;
            int right=0;
            int n=str.size();
            for(int i=0;i<n/2;i++)
            {
              left+=(str[i]);
            }
            for(int i=n/2;i<n;i++)
            {
                right+=(str[i]);
            }
            if(left==right)
            {
                count++;
            }
        }
        return count;
    }
};