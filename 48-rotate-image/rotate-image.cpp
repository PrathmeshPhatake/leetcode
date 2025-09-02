class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>ans=matrix;
        int n=matrix.size()-1;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++)
            {
                int nr=j;
                int  nc=n-i;
                ans[nr][nc]=matrix[i][j];
            }
        }
        matrix=ans;
    }
};