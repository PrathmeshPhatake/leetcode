class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        
        // Priority queue for Dijkstra's: {time, {x,y}}
        priority_queue<pair<int,pair<int,int>>, 
                      vector<pair<int,pair<int,int>>>, 
                      greater<>> pq;
        
        // Start from (0,0) at time 0
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        
        // Four possible moves
        vector<pair<int,int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        while(!pq.empty()) {
            auto [currTime, pos] = pq.top();
            auto [x, y] = pos;
            pq.pop();
            
            // Skip if we found a better path already
            if(currTime > dist[x][y]) continue;
            
            for(auto [dx,dy] : dirs) {
                int newX = x + dx;
                int newY = y + dy;
                
                if(newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    // First wait until moveTime if needed, then add 1 second for moving
                    int nextTime = max(currTime, moveTime[newX][newY]) + 1;
                    
                    if(nextTime < dist[newX][newY]) {
                        dist[newX][newY] = nextTime;
                        pq.push({nextTime, {newX, newY}});
                    }
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};