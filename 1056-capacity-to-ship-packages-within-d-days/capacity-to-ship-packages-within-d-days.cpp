class Solution {
public:
int func(vector<int>&weights,int cap)
{
    int n=weights.size();
    int loads=0;
    int days=1;
    for(int i=0;i<n;i++)
    {
        if(loads+weights[i]>cap)
        {
            days++;
            loads=weights[i];
        }
        else 
        {
            loads+=weights[i];
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int i=0;i<n;i++)
        {
            high+=weights[i];
        }
        while(low<=high)
        {
            int mid=(low+high)/2;
            int numberdays=func(weights,mid);
            if(numberdays<=days){
                high=mid-1;
            }else
            {
                low=mid+1;
            }
        }
        return low;
        
    }
};