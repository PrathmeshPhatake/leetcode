/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

// 1] if  root ==NULL || root==p|| root==q|| then return root
// 2] left== NULL  then return right 
// 3] right==NULL then return left 
// 4] both left and right are not null then we return ROOT


public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root==NULL || root==p|| root==q)
        {
            return root;
        }
        
        TreeNode* left=lowestCommonAncestor( root->left, p, q);
        TreeNode* right=lowestCommonAncestor( root->right, p, q);
        if(left==NULL)
        {
            return right;
        }
        else if(right==NULL)
        {
            return left;
        }
        //both are not null
        else
        {
            return root;
        }

    }
};