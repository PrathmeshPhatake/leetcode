class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>mp;
        for(auto it:bills){
            if(it==5){
                mp[it]++;
            }else if(it==10){
                if(mp[5]>0)
                {
                    mp[5]--;
                }else
                {
                    return false;
                }
                mp[it]++;
            }else if(it==20)
            {
                if(mp[5]>0 && mp[10]>0){
                    mp[5]--;
                    mp[10]--;
                }else if(mp[5]>2)
                {
                    mp[5]=mp[5]-3;
                }else
                {
                    return false;
                }
                mp[it]++;
            }
        }
        return true;
    }
};