// topo  return topo order with non cyclic element
// time compexity :O(V+E+VlogV)
//SPACE COMPLEXITY:O(V+E) FOR STORE THE REVERSE
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> reverseGraph(V);
        vector<int> indegree(V, 0);
        // O(V+E)
        //  Create reverse graph and calculate reverse  indegrees
        for (int i = 0; i < V; i++) {
            for (auto it : graph[i]) {
                reverseGraph[it].push_back(i);
                indegree[i]++;
            }
        }

        // Queue for processing nodes with 0 indegree
        //O(V)
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        //O(V+E)
        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (auto neighbor : reverseGraph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

       //O(V*LOG(V))
        // Sort safe nodes to return in required order
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};