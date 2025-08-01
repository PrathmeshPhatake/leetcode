class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>nex(m),cur(m),pre(m);
        for(int i=0;i<m;i++)
        {
            nex[i]=matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<m;j++){
                int prev=INT_MAX,curr=INT_MAX,next=INT_MAX;
                if(j>0)
                {
                    prev=nex[j-1];
                }
                if(j<m-1)
                {
                    next=nex[j+1];
                }
                curr=nex[j];
                cur[j]=matrix[i][j]+min({prev,curr,next});
                
            }
            nex=cur;
        }
    int res=INT_MAX;
    for(int j=0;j<m;j++){
        res=min(res,nex[j]);
    }
    return res;

    }
};