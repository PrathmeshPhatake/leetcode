class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int>V;
        V.push_back(1); 
        int i=0,j=0,k=0;
        for(int a=0;a<n;a++)
        {
           V.push_back(min({V[i]*2,V[j]*3,V[k]*5}));
           int mini=V.back();
           if(mini==V[i]*2) i++;
           if(mini==V[j]*3) j++;
           if(mini==V[k]*5) k++;
        }
        return V[n-1];
    }
};