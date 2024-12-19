class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt=0;
        int diff=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            diff+=(arr[i]-i);
            cnt+=(diff==0);
        }
        return cnt;
    }
};