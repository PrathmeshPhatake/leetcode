class Solution {
public:
void func(vector<vector<int>>&ans,vector<int>&res,vector<int>&candidates,int i,int target)
{
    int n=candidates.size();
    if(i==n)
    {
        if(target==0)
        {
            ans.push_back(res);
        }
        return;
    }
    if(target-candidates[i]>=0)
    {
        res.push_back(candidates[i]);
        func(ans,res,candidates,i,target-candidates[i]);
        res.pop_back();
    }
    func(ans,res,candidates,i+1,target);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>res;
        func(ans,res,candidates,0,target);
        return  ans;
    }
};