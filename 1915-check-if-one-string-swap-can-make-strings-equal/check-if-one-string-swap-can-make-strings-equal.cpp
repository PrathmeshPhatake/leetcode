class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        map<int,int>mp;
        int n=s1.size();
        int m=s2.size();
        if(n!=m) return false;
        int count=0;
        for(int i=0;i<n;i++)
        {
            mp[s1[i]]++;
            mp[s2[i]]--;
            if(s1[i]!=s2[i])
            {
                count++;

            }
        }
        for(auto it:mp)
        {
            if(it.second>0 || it.second<0)
            {
                return  false;
            }
        }
        if(count>2) return false;
        return true;

    }
};