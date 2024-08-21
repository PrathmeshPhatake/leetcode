class Solution {
public:
    static void shorten(string& s, int& n){
        int sz=s.size();
        n=1;
        
        char cur;
        for(int l=0, r=1; r<sz; r++){
            cur=s[r];
            while(l<r && s[l]==cur) l++;
            if (r<sz && s[l]!=cur){
                s[n++]=s[r];
                l=r;
            }
        }
        s.resize(n);
   
    }
    static int strangePrinter(string& s) {
        int n;
        shorten(s, n);
   
        int dp[101][101]={0};
        for(int i=n-1; i>=0; i--){// backward
            dp[i][i]=1;// base case;
            for(int j=i+1; j<n; j++){// forward
                if (s[i]==s[j]){
                    dp[i][j]=dp[i][j-1];
                    continue;
                }
                int x=dp[i][j-1]+1;
                for(int k=i+1; k<j-1; k++){
                    if (s[k]==s[j]){
                        x=min(x, dp[i][k-1]+dp[k][j-1]);
                        k++;// no successive duplicates
                    }
                }
                dp[i][j]=x;
            }
        }
        return dp[0][n-1];
    }
};