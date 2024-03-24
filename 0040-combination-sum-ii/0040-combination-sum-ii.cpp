class Solution {
    private:
    void subarray(vector<int>&temp,vector<vector<int>>&ans,vector<int>&given,int index,int sum,int target)
    {
        //base case
        if(sum==target)
        {
            ans.push_back(temp);
            return;
        }
        if(index==given.size() || sum>target)
        {
            return ;
        }
        //taking element 
        sum=sum+given[index];
        temp.push_back(given[index]);
        subarray(temp,ans,given,index+1,sum,target);
        sum-=given[index];
        temp.pop_back();
        // this for avoid duplicate in subarray 
        while(index+1<given.size() && given[index]==given[index+1])
        {
            index++;
        }
        //NON TAKING ELEMENT 
       subarray(temp,ans,given,index+1,sum,target);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        int index=0;
        int sum=0;
        subarray(temp,ans,candidates,0,0,target);
        return ans;
    }
};