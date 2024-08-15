class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s2.size();
        int n=s1.size();
        if(n>m)  return false; 
        
        vector<int>s1Count(26,0),s2Count(26,0);
        for(int i=0;i<n;i++)
        {
            s1Count[s1[i]-'a']++;
            s2Count[s2[i]-'a']++;
        }
        // slidign window 
        for(int i=0;i<=m-n;i++)
        {
            if(s1Count==s2Count)
            {
                return true;
            }
            if(i<m-n)
            {
                s2Count[s2[i]-'a']--;
                s2Count[s2[i+n]-'a']++;
            }
        }
        return false;
    }
};