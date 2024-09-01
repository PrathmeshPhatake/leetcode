class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row=mat.size();
        int col=mat[0].size();
        if(row*col!=r*c )
        {
            return mat;
        }
        vector<vector<int>>ans(r,vector<int>(c));
        vector<int>temp(r*c);
        int k=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                temp[k++]=mat[i][j];
            }
        }
        int x=0;
       for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                ans[i][j]=temp[x++];
            }
        }
        return ans;
    }
};