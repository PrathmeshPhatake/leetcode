/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Use map to store nodes at each horizontal distance
        map<int, vector<pair<int, int>>> mp; // Key: horizontal distance, Value: vector of pairs (depth, node value)
        vector<vector<int>> ans;
        int m = 0; // Horizontal distance
        int d = 0; // Depth

        // Populate the map
        vertical(root, m, d, mp);

        // Extract the values from the map and sort by depth
        for (auto it : mp) {
            // Sort the vector of pairs based on the depth first, and value second
            sort(it.second.begin(), it.second.end());
            vector<int> col;
            for (auto p : it.second) {
                col.push_back(p.second);
            }
            ans.push_back(col);
        }
        return ans;
    }

private:
    void vertical(TreeNode* root, int m, int d, map<int, vector<pair<int, int>>>& mp) {
        if (root == nullptr) {
            return;
        }
        // Insert the node into the map
        mp[m].push_back({d, root->val});

        // Traverse the left and right subtrees
        vertical(root->left, m - 1, d + 1, mp);
        vertical(root->right, m + 1, d + 1, mp);
    }
};