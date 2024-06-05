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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;
        vector<int> inorder(preorder);
        sort(inorder.begin(), inorder.end());
        map<int, int> in_map;
        for (int i = 0; i < inorder.size(); ++i) {
            in_map[inorder[i]] = i;
        }
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, in_map);
    }
    
    TreeNode* buildTree(vector<int>& preorder, int prestart, int preend,
                        vector<int>& inorder, int instart, int inend,
                        map<int, int>& in_map) {
        if (prestart > preend || instart > inend) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[prestart]);
        int root_in = in_map[preorder[prestart]];
        int num_left = root_in - instart;
        root->left = buildTree(preorder, prestart + 1, prestart + num_left, inorder, instart, root_in - 1, in_map);
        root->right = buildTree(preorder, prestart + num_left + 1, preend, inorder, root_in + 1, inend, in_map);
        return root;
    }
};