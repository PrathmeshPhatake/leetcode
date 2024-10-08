class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int count=0;
        for(auto it:s)
        {
            if(it==')')
            {
                if(!st.empty())
                st.pop(); 
                else
                count++;
            }
            else
            {
                st.push('(');
            }
        }
        return st.size()+count;
    }
};