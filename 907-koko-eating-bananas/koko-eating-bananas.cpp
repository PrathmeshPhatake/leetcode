class Solution {
public:
long long  func(vector<int>&piles,int speed){
long long totalHours = 0;
        for (int bananas : piles) {
            totalHours += ((long long)bananas + speed - 1) / speed;
        }
        return totalHours;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        // for(int i=1;i<=maxi;i++){
        //     int hours=func(piles,i);
        //     if(hours<=h) return i;
            
        // }
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long value=func(piles,mid);
            if(value<=h){
                ans=mid;
                high=mid-1;
            }else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};