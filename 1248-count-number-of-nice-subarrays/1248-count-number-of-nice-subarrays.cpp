class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count=0;
        int sub=0;
        int left=0;
        int n=nums.size();
        for(int right=0;right<n;right++)
        {
            if(nums[right]%2!=0)
            {
                count++;
            }
            while(count>k && left<right)
            {
                if(nums[left]%2!=0)
                {
                    count--;
                }
                left++;
            }
            if(count==k)
            {
                sub++;
                int temp_left=left;
                while(temp_left<right && nums[temp_left]%2==0)
                {
                    sub++;
                    temp_left++;
                }
            }

        }
        return sub;
    }
};