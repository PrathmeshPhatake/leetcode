class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
     int left=1;
     int ans=0;
     auto max_iter = std::max_element(nums.begin(), nums.end());
        int max_num = *max_iter; // Maximum element in nums

        while(left<=max_num)
        {
            int mid = left + (max_num - left) / 2;
            int sum=0;
            for(int i=0;i<nums.size();i++)
            {
                sum+=ceil(static_cast<double>(nums[i])/mid);
               
            }
            if(sum<=threshold){
                ans=mid;
                max_num=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }   
        return ans;
    }
};