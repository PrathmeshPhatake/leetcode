class Solution {
public:
void func(map<char,int>&mp,unordered_set<string>&st,string s)
{
    for(auto& it:mp)
    {
        if(it.second>0)
        {
            s+=it.first;
            it.second--;
            st.insert(s);
            func(mp,st,s);
            it.second++;
            s.pop_back();
        }
    }
}

    int numTilePossibilities(string tiles) {
        unordered_set<string>st;
        map<char,int>mp;
        int n=tiles.size();
        for(int i=0;i<n;i++)
        {
            mp[tiles[i]]++;
        }
        string s="";
        func(mp,st,"");
        return st.size();
    }
};