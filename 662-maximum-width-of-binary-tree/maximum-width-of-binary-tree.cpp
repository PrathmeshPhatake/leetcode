/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // formula for finf it 2*(parent index)+(l==1)||(r==2)
        if (root == NULL)
            return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int maxwidth = 0;
        while (!q.empty()) {
            int n = q.size();
            long long leftmost = q.front().second;
            long long rightmost = q.back().second;
            maxwidth = max(maxwidth, (int)(rightmost - leftmost + 1));
            for (int i = 0; i < n; i++) {
                auto [node, index] = q.front();
                q.pop();
                long long normalizedIndex = index - leftmost;
                if (node->left)
                    q.push({node->left, 2 * normalizedIndex + 1});
                if (node->right)
                    q.push({node->right, 2 * normalizedIndex + 2});
            }
        }
    return maxwidth;
    }
}
;