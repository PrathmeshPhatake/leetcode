class Solution {
public:
void func(vector<vector<int>>&ans,vector<int>&res,int i,int count,int sum,int n,int k)
{
    if(sum==n && count==k)
    {
        ans.push_back(res);
        return;
    }
    if(sum>n || count>k ||i>9)
    {
        return ;
    }
    res.push_back(i);
    func(ans,res,i+1,count+1,sum+i,n,k);
    res.pop_back();
    func(ans,res,i+1,count,sum,n,k);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>res;
        func(ans,res,1,0,0,n,k);
        return ans;

        
    }
};