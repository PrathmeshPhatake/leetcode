class Solution {
public:
    int maximumLength(string s) {
        map<string,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            int j=i;
            string str="";
            while(s[i]==s[j] && j<n)
            {
                str+=s[j];
                j++;
                mp[str]++;
            }
            
        }
        int count=-1;
        for(auto it:mp)
        {
            
            if(it.second>=3)
            {
                int size=it.first.size();
                count=max(count,size);
            }
        }
        return count;
    }
};