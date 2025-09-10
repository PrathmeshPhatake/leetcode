class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>st;
        int l=0;
        int r=0;
        int maxi=0;
        int n=s.length();
        while(r<n){
            if(st.find(s[r])!=st.end())
            {
                while(l<r && st.find(s[r])!=st.end()){
                    st.erase(s[l]);
                    l++;
                }
            }
            st.insert(s[r]);
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};