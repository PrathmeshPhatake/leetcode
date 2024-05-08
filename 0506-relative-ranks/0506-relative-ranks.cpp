class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        //sort given vector in increasing oreder
        vector<int>sortSore=score;
        sort(sortSore.begin(),sortSore.end());
        reverse(sortSore.begin(),sortSore.end());
        vector<string>medals{"Gold Medal","Silver Medal","Bronze Medal"};
        unordered_map<int,string>mp;
        //first three value has medals 
        //we store in map mp[sortScore[i]]=if get medals otherwise position 
        for(int i=0;i<sortSore.size();i++)
        {
            if(i<3)
            {
                mp[sortSore[i]]=medals[i];
            }
            else
            {
                mp[sortSore[i]]=to_string(i+1);
            }
        }
        vector<string>ans;
        for(int s:score)
        {
            ans.push_back(mp[s]);
        }
        return ans;

    }
};