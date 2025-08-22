class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int numrow=grid.size();
        int numcol=grid[0].size();
        
        int maxX=-1;
        int minX=numcol;
        int  minY=numrow;
        int maxY=-1;
        for(int i=0;i<numrow;i++)
        {
            for(int j=0;j<numcol;j++)
            {
                if(grid[i][j]==1)
                {
                    maxX=max(maxX,i);
                     minX=min(minX,i);
                    maxY=max(maxY,j);
                     minY=min(minY,j);
                }
            }
        }
        return ( maxX-minX+1)* (maxY-minY+1);
    }
};