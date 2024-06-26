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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return create(root1, root2);
    }
    
    TreeNode* create(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) {
            return NULL;
        }
        
        TreeNode* temp;
        if (root1 == NULL) {
            temp = new TreeNode(root2->val);
        } else if (root2 == NULL) {
            temp = new TreeNode(root1->val);
        } else {
            temp = new TreeNode(root1->val + root2->val);
        }
        //if root left exist other wise NULL
        temp->left = create(root1 ? root1->left : NULL, root2 ? root2->left : NULL);
        temp->right = create(root1 ? root1->right : NULL, root2 ? root2->right : NULL);
        
        return temp;
    }
};
