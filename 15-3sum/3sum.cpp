class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // we used threepointer i,j,k and i is const and j and k at first and end of array 
        // then i+j+k<0 j+1; else k-- in if(i<j)
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i!=0 && nums[i]==nums[i-1]) continue;
           int j=i+1;
           int k=n-1;
           while(j<k)
           {
             int diff=nums[i]+nums[j]+nums[k];
             if(diff<0)
             {
                j++;
             }else if(diff>0)
             {

                k--;
             }else
             {
                vector<int>temp={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
             }
           }   
        }
        return ans;
    }
};