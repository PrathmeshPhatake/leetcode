class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, INT_MAX));
        for(int i=0;i<n;i++) mat[i][i]=0;
        for (auto it : edges) {
            mat[it[0]][it[1]] = it[2];
            mat[it[1]][it[0]] = it[2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(mat[i][k]!=INT_MAX && mat[k][j]!=INT_MAX)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        // we want node
        int result=-1;
        int maxcount=INT_MAX;
        for (int i = 0; i < n; i++) {
            int count=0;
            for (int j = 0; j < n; j++) {
               if(i!=j && mat[i][j]<=distanceThreshold)
               {
                count++;
               }
            }

            if(count<=maxcount && result<=i){
             maxcount=min(maxcount,count);
             result=i;
            }
        }
        return result;
    }
};