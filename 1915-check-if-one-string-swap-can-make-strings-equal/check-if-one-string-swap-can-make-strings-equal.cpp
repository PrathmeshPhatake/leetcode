class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        map<char,int>mp;
        int n=s1.size();
        int m=s2.size();
        int count=0;
        if(m!=n) return false;
        for(int i=0;i<n;i++){
            mp[s1[i]]++;
            mp[s2[i]]--;
            if(s1[i]!=s2[i])
            {
                count++;
            }
        }
        for(auto  it:mp)
        {
            if(it.second>0 ||it.second<0) return false;
        }
        return count>2?false:true;
        
    }
};