class Solution {
public:
vector<char>arr{'a','b','c'};
void func(int n,set<string>&st,string s)
{
    if(n==0)
    {
        st.insert(s);
        return;
    }
    for(int i=0;i<3;i++)
    {
        if(s.empty() ||s.back()!=arr[i])
        {
            func(n-1,st,s+arr[i]);
        }
    }

}
    string getHappyString(int n, int k) {
        set<string>st;
        func(n,st,"");
        if(k>st.size())return "";
        auto it=st.begin();
        advance(it,k-1);
        return *it;
    }
};