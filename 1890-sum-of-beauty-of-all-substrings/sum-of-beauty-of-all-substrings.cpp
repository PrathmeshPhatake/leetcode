class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
           unordered_map<char,int>mp;
            int maxi=INT_MIN;
            int mini=INT_MAX;
            for(int j=i;j<n;j++)
            {
                mp[s[j]]++;
                maxi=max(maxi,mp[s[j]]);
                mini=INT_MAX;
                for(auto it:mp)
                {
                    if(it.second>0)
                    {
                        mini=min(mini,it.second);
                    }
                }
                sum+=(maxi-mini);
            }
        }
        return sum;
    }
};