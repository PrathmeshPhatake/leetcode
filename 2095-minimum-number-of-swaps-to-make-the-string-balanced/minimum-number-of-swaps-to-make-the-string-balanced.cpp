class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(auto it :s)
        {
            if( it==']')
            {
                if(!st.empty())
                st.pop();
            }
            else
            {
                st.push('[');
            }
        }
        return ceil(static_cast<double>(st.size())/2);
    }
};