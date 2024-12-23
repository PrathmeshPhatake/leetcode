class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);  // Marker for level
        vector<int> temp;
        int ans = 0;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                temp.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            } else {
                // Process the current level
                if (!q.empty()) q.push(NULL);
                
                // Sorting logic to calculate minimum swaps
                vector<int> sorted(temp.begin(), temp.end());
                sort(sorted.begin(), sorted.end());
                
                unordered_map<int, int> indexMap;
                for (int i = 0; i < sorted.size(); i++) {
                    indexMap[sorted[i]] = i;
                }

                vector<bool> visited(temp.size(), false);
                int count = 0;

                for (int i = 0; i < temp.size(); i++) {
                    if (visited[i] || indexMap[temp[i]] == i) continue;

                    int cycleSize = 0;
                    int j = i;
                    while (!visited[j]) {
                        visited[j] = true;
                        j = indexMap[temp[j]];
                        cycleSize++;
                    }

                    if (cycleSize > 1) {
                        count += (cycleSize - 1);
                    }
                }

                ans += count;
                temp.clear();
            }
        }

        return ans;
    }
};
