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
bool isbulid(TreeNode*root,long  maxval,long  minval)
{
    if(!root)
    {
        return true;
    }
    if(root->val<=minval || root->val>=maxval)
    {
        return false;
    }
    return isbulid(root->left,root->val, minval)&& isbulid(root->right,maxval,root->val);
}
    bool isValidBST(TreeNode* root) {
        return isbulid(root,LONG_MAX,LONG_MIN);
    }
};