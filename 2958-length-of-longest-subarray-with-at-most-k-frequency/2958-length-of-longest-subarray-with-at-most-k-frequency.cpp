// // m=sizeof map and n=size of nums
// //time complexity=O(N*LOG(M)+M)
// //SPACE COMPLEXITY=O(N)
// class Solution {
// public:
//     int maxSubarrayLength(vector<int>& nums, int k) {
//         int count =0;
//         map<int,int>mp;
//         //
//         for(int i=0;i<nums.size();i++)
//         {
//             mp[nums[i]]++;
//         }
//         for(auto cnt:mp)
//         {
//             if(cnt.second>k)
//             {
//                 count=count+k;
//             }
//             else
//             {
//                 count+=cnt.second;
//             }
//         }
//         return count;
//     }
// };
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0,i=0,j=0;
        map<int,int>mp;
        while(j<nums.size())
        {
            mp[nums[j]]++;
            while(i<=j && mp[nums[j]]>k)
            {
                mp[nums[i]]--;
                i++;

            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};