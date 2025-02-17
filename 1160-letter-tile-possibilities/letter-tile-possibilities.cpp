class Solution {
public:
void func(unordered_map<char,int>mp, set<string>&st,string s)
{
     for(auto&it :mp)
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
        unordered_map<char,int>mp;
        int n=tiles.size();
        set<string>st;
        for(int i=0;i<n;i++)
        {
            mp[tiles[i]]++;
        }
        func(mp,st,"");
        return st.size();
    }
};