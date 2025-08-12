class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int maxi=*max_element(arr.begin(),arr.end());
        int missing=0;
        for(int i=1;i<maxi;i++)
        {
            auto it=find(arr.begin(),arr.end(),i);
            if(it==arr.end())
            {
                missing++;
            }
            if(missing==k)return i;
        }
        return maxi+(k-missing);
    }
};