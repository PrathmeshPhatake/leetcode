class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // adjmatix
        vector<vector<int>> adjmatrix(n, vector<int>(n, INT_MAX));
        for (auto it : edges) {
            adjmatrix[it[0]][it[1]] = it[2];
            adjmatrix[it[1]][it[0]] = it[2];
            
        }
        // floyd warshal algorithm
        for (int i = 0; i < n; i++)
            adjmatrix[i][i] = 0;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (adjmatrix[i][k] == INT_MAX ||
                        adjmatrix[k][j] == INT_MAX)
                        continue;

                    adjmatrix[i][j] =
                        min(adjmatrix[i][j], adjmatrix[i][k] + adjmatrix[k][j]);
                }
            }
        }
        //adjcent vertex
        int citycnt = n;
        int cityNo = -1;

        for (int city = 0; city < n; city++) {
            int cnt = 0;
            for (int adjcity = 0; adjcity < n; adjcity++) {
                if (adjmatrix[city][adjcity] <= distanceThreshold) {
                    cnt++;
                }
            }
            if (cnt <=citycnt) {
                citycnt = cnt;
                cityNo = city;
            }
        }
        return cityNo;
    }
};