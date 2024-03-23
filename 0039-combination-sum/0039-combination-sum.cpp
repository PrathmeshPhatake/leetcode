class Solution {
    private:
    void subarray(vector<int>&temp,vector<vector<int>>&ans,vector<int>&given,int index,int sum,int target)
    {
        //base case
        if(index==given.size() || sum>target)
        {
            return ;
        }
        if(sum==target)
        {
            ans.push_back(temp);
            return;
        }
        sum=sum+given[index];
        temp.push_back(given[index]);
        subarray(temp,ans,given,index,sum,target);
        sum-=given[index];
        temp.pop_back();
       subarray(temp,ans,given,index+1,sum,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        int index=0;
        int sum=0;
        subarray(temp,ans,candidates,index,sum,target);
        return ans;
    }
};