class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        // int total=0;
        vector<int>ones;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            if(boxes[i]=='1')
            {
                ones.push_back(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            int total=0;
           for(auto it:ones)
           {
            if(it!=i) total+=abs(i-it);
           }
           ans[i]=total;
        }
        return ans;   
    }
};