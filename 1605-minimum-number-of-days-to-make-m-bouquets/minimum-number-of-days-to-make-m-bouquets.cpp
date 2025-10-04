class Solution {
public:
bool ispossibel(vector<int>&bloomday,int m,int k,int day)
{
    int cnt=0;
    int nob=0;
    for(int i=0;i<bloomday.size();i++){
        if(bloomday[i]<=day)
        {
            cnt++;
        }else
        {
            nob+=(cnt/k);
            cnt=0;
        }
    }
    nob+=(cnt/k);
    cnt=0;
    if(nob>=m) return true;
    return false;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        if(bloomDay.size()<(long long )m*k) return -1;
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(ispossibel(bloomDay,m,k,mid))
            {
                ans=mid;
                high=mid-1;
            }else
            {
                low=mid+1;
            }
            
        }
        return  ans;
    }
};