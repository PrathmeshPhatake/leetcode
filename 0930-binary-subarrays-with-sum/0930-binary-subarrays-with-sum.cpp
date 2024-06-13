//TIME COMPLEXITY:O(2n);
//SPACE COMPLEXITY:O(1);

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int left=0;
        int sum=0;
        int count=0;
        for(int right=0;right<n;right++)
        {
            sum+=nums[right];
            

            while(left<right && sum>goal)
            {
                sum-=nums[left];
                left++;
            }
            //this is for check for if goal are same but check left moves which are
            if(sum==goal)
            {
                count++;
                int temp_left=left;
                while(temp_left<right && nums[temp_left]==0)
                {
                    count++;
                    temp_left++;
                }
            }
        }
        return count;
    }
};