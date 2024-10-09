class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        stack<char>st;
        int n=s.size();
        int i=0;
        while(i<n)
        {
            if(s[i]=='(')
            {
                st.push('(');
            }
            else
            {
                if(!st.empty())
                {
                    st.pop();
                }
                else
                {
                    ans++;
                }
                if(i+1<n && s[i+1]==')')
                    {
                        i++;
                    }
                    else
                    {
                        ans++;

                    }
                    
            }
            i++;
        }
      
        return st.size()*2+ans;
    }
};