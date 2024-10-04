class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        int total=0;
        for(auto it:skill)
        {
            total+=it;
        }
        if(total%(n/2)!=0) return -1;
        sort(skill.begin(),skill.end());
        long long  product=0;
        int i=0;
        int j=n-1;
        int sum=skill[0]+skill[n-1];
        while(i<j)
        {
            if(sum==(skill[i]+skill[j]))
            {
               product+=skill[i]*skill[j];
               
               i++;
               j--;
            }
            else{
                return -1;
            }
            
        }
        return product;
    }
};