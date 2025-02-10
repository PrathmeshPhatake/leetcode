class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(auto it:s)
        {
            if(it>='a' && it<='z')
            {
                st.push(it);

            }
            else
            {
                st.pop();
            }
        }
        string temp;
        while(!st.empty())
        {
           temp+=st.top();
           st.pop();
            
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};