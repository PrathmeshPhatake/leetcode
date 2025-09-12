class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int j=0;
        int n=fruits.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            mp[fruits[i]]++;
            if(mp.size()<=2){
                maxi=max(maxi,i-j+1);
            }else
            {
                while( mp.size()>2 && j<i)
                {
                    mp[fruits[j]]--;
                    if(mp[fruits[j]]==0) mp.erase(fruits[j]);
                    j++;
                }
            }
        }
        return maxi;
    }
};