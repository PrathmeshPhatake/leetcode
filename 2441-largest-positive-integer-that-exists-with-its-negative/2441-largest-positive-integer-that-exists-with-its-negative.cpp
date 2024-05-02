class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int max=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>max)
            {
                int temp=-1*(nums[i]);
                auto it=find(nums.begin(),nums.end(),temp);
                //neagative value find then this store  in that 
                if(it!=nums.end())
                {
                    max=abs(temp);
                }
            }
        }
        return max;
    }
};