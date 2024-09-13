class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto it:queries)
        {
            int temp=0;
            for(int i=it[0];i<=it[1];i++)
            {
                temp^=arr[i];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};