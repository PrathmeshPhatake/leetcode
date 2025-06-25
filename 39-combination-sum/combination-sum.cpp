class Solution {
public:
void func(vector<vector<int>>&res,vector<int>ans,int target,int i,vector<int>candidates,int sum)
{
    int n=candidates.size();
    if(i==n)
    {
        if(sum==target)
        {
            res.push_back(ans);
        }
        return;
    }
    if(sum+candidates[i]<=target)
    {
        sum+=candidates[i];
        ans.push_back(candidates[i]);
        func(res,ans,target,i,candidates,sum);
        ans.pop_back();
        sum-=candidates[i];
    }
    func(res,ans,target,i+1,candidates,sum);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>ans;
        func(res,ans,target,0,candidates,0);
        return res;
    }
};