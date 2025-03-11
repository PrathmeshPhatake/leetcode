class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0;
        int n=s.size();
        vector<int>vec(3,0);
        int ans=0;
        for(int right=0;right<n;right++)
        {
            vec[s[right]-'a']++;
            while(vec[0]>0 && vec[1]>0 && vec[2]>0)
            {
                ans+=n-right;
                vec[s[left]-'a']--;
                left++;
            }
        }
        return ans;
    }
};