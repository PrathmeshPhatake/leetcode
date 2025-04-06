class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n , 1) , hash(n);
        int maxi = 1;
        int lastindex = 0;

        // sort the array
        sort(nums.begin() , nums.end());

        for(int ind = 0 ; ind < n ; ind++ ){

            hash[ind] = ind;

            for(int prev = 0 ; prev < ind ; prev++){

                if(nums[ind] % nums[prev] == 0 && 1 + dp[prev] > dp[ind]){

                    dp[ind] = 1 +  dp[prev];
                    hash[ind] = prev; // update prev element index in hash

                }
            }

            if(maxi < dp[ind]){
                maxi = dp[ind];
                lastindex = ind;
            }

        }

        vector<int>temp;
        temp.push_back(nums[lastindex]);

        while(hash[lastindex] != lastindex){

            lastindex = hash[lastindex];
            temp.push_back(nums[lastindex]);

        }
     
        reverse(temp.begin() , temp.end());

        return temp; 
    }
};