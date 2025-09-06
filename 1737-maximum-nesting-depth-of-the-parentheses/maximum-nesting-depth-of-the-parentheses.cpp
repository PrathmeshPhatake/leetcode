class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int maxi=0;
        if(s.length()==0) return 0;
        for(auto it:s){
            if(it=='(')
            {
                st.push('(');
                
            }else if(it==')')
            {
                maxi=max(maxi,(int)st.size());
                st.pop();
            }
        }
        return maxi;
    }
};