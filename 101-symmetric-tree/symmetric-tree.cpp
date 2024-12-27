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
bool func(TreeNode* l,TreeNode* r)
{
    // base case 
    if( l==NULL && r==NULL) return true;
    // check valid or not 
    if(l==NULL || r==NULL || l->val!=r->val) return false;
    
    return func(l->left,r->right) && func(l->right,r->left);
    
}
    bool isSymmetric(TreeNode* root) {
        if(root==NULL ) return true;
        return func(root->left,root->right);
    }
};