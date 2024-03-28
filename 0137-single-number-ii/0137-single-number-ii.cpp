class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        //this for check nth BITSINDEX
        for(int bitIndex=0;bitIndex<32;bitIndex++)
        {
            int cnt=0;
            for(int num=0;num<n;num++)
            {
                if(nums[num]&(1<<bitIndex))
                {
                    cnt++;
                }
            }
            if(cnt%3==1)
            {
                ans=ans|(1<<bitIndex);
            }
        }
        return ans;
    }
};