class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[i]=nums[i];
        }
        set<int>ans;
        vector<int>ans1;
        for(int i=0;i<n;i++){
            int diff=target-nums[i];
            for(auto it:mp){
                if(it.second==diff && it.first!=i){
                    ans.insert(i);
                    ans.insert(it.first);
                    break;
                }
            }
        }
        for(auto it:ans)
        {
            ans1.push_back(it);
        }
        return ans1;
    }
};