class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            int maxiCount=INT_MIN;
            int miniCount=INT_MAX;
            vector<pair<char, int>> vec;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;

            maxiCount=max(maxiCount,mp[s[j]]);
            miniCount=INT_MAX;
           for(auto it:mp)
           {
             if(it.second>0)
             {
                miniCount=min(miniCount,it.second);
             }
           }

            sum+=(maxiCount-miniCount);
            }
        }
        return sum;
    }
};