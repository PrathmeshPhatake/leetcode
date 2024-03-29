class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int max_num = *max_element(nums.begin(),nums.end()),count = 0;
        long long int left = 0,right = 0,ans = 0;
        while(right<nums.size()){
            if(nums[right] == max_num)count++;
            //this is a swithch window 
            while(count>=k){
                if(nums[left]==max_num)count--;
                left++;
                ans += nums.size()-right;
            }    
            right++;
        }


        return ans;
        
    }
};
//this solve upto remeaning 10 test case 
// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int k) {
//         auto maxElement_it= max_element(nums.begin(), nums.end());
//         int maxElement= *maxElement_it;
//         int maxCount=count(nums.begin(),nums.end(),maxElement);
//         long long  ans=0;
        
//         if(k>maxCount)
//         {
//             return ans;
//         }
        
//        else
//        {
//          for(int i=0;i<nums.size();i++)
//         {
//              int cnt=0;
//             for(int j=i;j<nums.size();j++)
//             {
               
//                 if(maxElement==nums[j])
//                 {
//                     cnt++;
//                 }
//                 if(cnt>=k)
//                 {
//                     ans++;
//                 }
//             }
//         }
//        }
//         return ans;
//     }
// };