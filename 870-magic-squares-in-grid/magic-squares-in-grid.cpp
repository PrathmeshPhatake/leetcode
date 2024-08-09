class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n<3 ||m<3 ) return 0;
        int count=0;
        for(int i=0;i<n-2;i++)
        {
            for(int j=0;j<m-2;j++)
            {
                int r=i;
                int c=j;
                set<int>st;
                bool flag=true;
                // check distinct element 
                for(int x=r;x<r+3;x++)
                {
                    for(int y=c;y<c+3;y++)
                    {
                        int val=grid[x][y];
                        if(val < 1 || val > 9 || !st.insert(val).second) {
                            flag = false;
                            break;
                        }
                        if(!flag) break;
                    }
                    if(!flag) break;
                }
                if(!flag) continue;

                if(st.size()!= 9 || *st.begin()!=1 || *st.rbegin()!=9) return false;
                int sum1=grid[r][c]+grid[r][c+1]+grid[r][c+2];

                int rowsum=0;
                int colsum=0;
              
                for (int k = 0; k < 3; k++) {
                    int rowSum = grid[r + k][c] + grid[r + k][c + 1] + grid[r + k][c + 2];
                    int colSum = grid[r][c + k] + grid[r + 1][c + k] + grid[r + 2][c + k];
                    
                    if (rowSum != sum1 || colSum != sum1) {
                        flag = false;
                        break;
                    }
                }
                if(sum1!=grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]  || sum1!=grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c])
                {
                    flag=false ;
                    
                }
                if(flag)
                {
                    count++;
                }
            }
        }
        return count;
    }
};