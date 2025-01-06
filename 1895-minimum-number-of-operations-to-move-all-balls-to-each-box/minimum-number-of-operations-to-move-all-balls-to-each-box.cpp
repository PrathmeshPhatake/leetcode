class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            int j=i+1;
            int k=i-1;
            int total=0;
            int count=0;
            while(j<n)
            {
                count++;
                if(boxes[j]=='1')
                {
                    total+=count;
                }
                j++; 
            }
            count=0;
            while(k>=0)
            {
                count++;
                if(boxes[k]=='1')
                {
                    total+=count;
                }
                k--;
            }
            ans[i]=total;
        }
        return ans;
        
    }
};