class Solution {
    private:
    void printf(vector<vector<int>>&ans,vector<int>&nums,vector<int>&temp,int index)
    {
        ans.push_back(temp);
        //we first add all element with unique 
        for(int i=index;i<nums.size();i++)
        {
            if(i!=index && nums[i]==nums[i-1])
            //this is for add value but not repeating  in same temp vector element 
            continue;
            temp.push_back(nums[i]);
            printf(ans,nums,temp,i+1);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //2 -D VECTOR
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        printf(ans,nums,temp,0);
        return ans;
    }
};