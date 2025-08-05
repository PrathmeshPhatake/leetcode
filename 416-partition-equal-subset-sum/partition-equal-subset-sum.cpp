class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)
        {
            return false;
        }
        sum=sum/2;
        vector<bool>prev(sum+1,false);
        prev[0]=true;
        if(nums[0]>0 && nums[0]<=sum)
        {
        prev[nums[0]]=true;
        }
        for(int i=1;i<n;i++)
        {
            vector<bool>curr(sum+1,false);
            for(int j=1;j<=sum;j++)
            {
                bool ntake=prev[j];
                bool take=false;
                if(nums[i]<=j)
                {
                    take=prev[j-nums[i]];
                }
                curr[j]=take||ntake;
            }
            prev=curr;
        }
        return prev[sum];
    }
};