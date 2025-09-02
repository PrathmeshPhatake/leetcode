class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>>ans=matrix;
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
                    // made coloumn zero
                    for(int x=0;x<c;x++)
                    {
                        ans[i][x]=0;
                    }
                    for(int y=0;y<r;y++)
                    {
                        ans[y][j]=0;
                }
                }
            }
        }
         matrix=ans;
    }
};