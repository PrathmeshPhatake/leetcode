class Solution {
    // ASCENDING ORDER
static bool sortValueByvalue(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.second<b.second;
}
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        vector<pair<int,int>>vec(mp.begin(),mp.end());
        // sort(vec.begin(),vec.end(),sortValueByvalue);
        //sort value by key
        sort(vec.begin(),vec.end(),[](pair<int,int>&a,pair<int,int>&b){
            if(a.second==b.second)
            {
                return a.first>b.first;
            }
            return a.second<b.second;
        });
        for(auto it:vec)
        {
            for(int i=0;i<it.second;i++)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};