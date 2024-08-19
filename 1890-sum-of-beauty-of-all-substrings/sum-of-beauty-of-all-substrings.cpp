class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++)
            {
                mp[s[j]]++;
              vector<pair<char,int>>vec(mp.begin(),mp.end());
                // sort reverse
                sort(vec.begin(),vec.end(),[](const pair<char,int>&a,const pair<char,int>&b){
                    return a.second > b.second;
                });
                if(!vec.empty())
                {

                sum+=(vec[0].second-vec.back().second);
                }
            }

        }
        return sum;
    }
};