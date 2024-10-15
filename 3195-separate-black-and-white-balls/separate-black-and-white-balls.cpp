class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        long long ans=0;
        int white=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                ans+=white;
            }
            else
            {
                white++;
            }
        }
        return ans;
    }
};
