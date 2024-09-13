class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();

        vector<int>prefix(n+1,0);
        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i]^arr[i];
        }
        vector<int>ans;
        for(auto it:queries)
        {
            int left=it[0];
            int right =it[1];
            ans.push_back(prefix[left]^prefix[right+1]);

        }
        return ans;
    }
};