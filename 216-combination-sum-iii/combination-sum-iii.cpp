class Solution {
    void sub(vector<vector<int>>&ans,vector<int>&temp,int count,int sum,int n,int k,int i)
    {
        if(count==k)
        {
            if(sum==n)
            {
                ans.push_back(temp);
            }
            return;

        }
        // overflow handling;
        if(i>9)return;
        temp.push_back(i);
        sub(ans,temp,count+1,sum+i,n,k,i+1);
        temp.pop_back();
        sub(ans,temp,count,sum,n,k,i+1);

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        sub(ans,temp,0,0,n,k,1);
        return ans;
    }
};