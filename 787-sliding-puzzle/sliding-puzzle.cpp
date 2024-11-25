#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // Target board state
        string target = "123450";
        string start;
        
        // Convert board to string representation
        for (const auto& row : board) {
            for (int num : row) {
                start += to_string(num);
            }
        }
        
        // Possible moves for the 0 tile (based on 2x3 grid layout)
        vector<vector<int>> directions = {
            {1, 3},    // 0 can move to indices 1 and 3
            {0, 2, 4}, // 1 can move to indices 0, 2, and 4
            {1, 5},    // 2 can move to indices 1 and 5
            {0, 4},    // 3 can move to indices 0 and 4
            {1, 3, 5}, // 4 can move to indices 1, 3, and 5
            {2, 4}     // 5 can move to indices 2 and 4
        };
        
        // BFS setup
        queue<pair<string, int>> q; // {current board state, move count}
        unordered_set<string> visited; // To avoid revisiting states
        q.push({start, 0});
        visited.insert(start);
        
        // BFS loop
        while(!q.empty())
        {
            auto [current,count]=q.front();
            q.pop();
            if(current==target)return count;
            int zeropos=current.find('0');
            for(int nextpos:directions[zeropos])
            {
                string temp=current;
                swap(temp[nextpos],temp[zeropos]);
                if(!visited.count(temp))
                {
                    q.push({temp,count+1});
                    visited.insert(temp);
                }
            }
        }
        
        // If no solution is found
        return -1;
    }
};
