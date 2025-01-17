class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            count^=derived[i];
        }
        return count==0?true:false;
    }
};