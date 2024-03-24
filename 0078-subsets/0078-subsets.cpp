class Solution {
    private:
    void prints( vector<vector<int>>& ans,vector<int>& temp,vector<int>& given,int index)
    {
        //BASE CASE
        if(index==given.size())
        {
            ans.push_back(temp);
           return;
        }
        //taking 
        temp.push_back(given[index]);
        prints(ans,temp,given,index+1);
        //non taking
        temp.pop_back();
        prints(ans,temp,given,index+1);

    }
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        prints(ans,temp,nums,0);
        return ans;
    }
};