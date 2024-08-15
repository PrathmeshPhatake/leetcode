class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>mp;
        for(auto it:bills)
        {
            if(it==5)
            {
                mp[it]++;
            }
            else if(it==10)
            {
                if(mp[5]<1)
                {
                    return false;
                }
                else 
                {
                    mp[10]++;
                    mp[5]--;
                }
            }
            else
            {
                if((mp[10]>0 && mp[5]<1) ||(mp[10]<1 && mp[5]<3) )
                {
                    return false;
                }
                else
                {
                    if(mp[5]>=3 &&mp[10]<1)
                    {
                        mp[20]++;
                       mp[5]-=3;
                    }
                    else
                    {
                        mp[10]--;
                        mp[5]--;
                        mp[20]++;
                    }
                }
            }
        }
        return true;
    }
};