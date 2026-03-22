class Solution {
public:
void func(vector<vector<int>>&ans,vector<int>temp,int i,int k,int n)
{
    if(i>9)
    {
        if(n==0 && k==0)
        {
            ans.push_back(temp);
        }
        return;
    }
    if(i<=n){
        temp.push_back(i);
        func(ans,temp,i+1,k-1,n-i);
        temp.pop_back();
    }
    func(ans,temp,i+1,k,n);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        func(ans,temp,1,k,n);
        return ans;
    }
};