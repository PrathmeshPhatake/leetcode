class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for(auto ch:expression)
        {
            if(ch=='(' ||ch==',')continue;
            else if(ch=='&' || ch=='|' || ch=='!' || ch=='t' || ch=='f')
            {
                st.push(ch);
            }
            else
            {
                bool hasTrue=false;
                bool hasFalse=false;
                while(st.top()!='|' && st.top()!='&' && st.top()!='!')
                {
                    char ch=st.top();
                    st.pop();
                    if(ch=='t')
                    hasTrue=true;
                    else if(ch=='f')
                    hasFalse=true;
                }
                char op=st.top();
                st.pop();
                if(op=='|'){
                    st.push(hasTrue?'t':'f');
                }
                else if(op=='&'){
                    st.push(hasFalse?'f':'t');
                }
                else if(op=='!'){
                    st.push(hasTrue?'f':'t');
                }
            }
        }
            return st.top()=='t';
    }
};