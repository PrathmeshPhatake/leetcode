class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            int sum=2*arr[i];
            auto it=find(arr.begin(),arr.end(),sum);
            if(it!=arr.end() && (it-arr.begin() !=i))
            {
                return true;
            }
        }
        return false;
    }
};