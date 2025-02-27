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
int func(TreeNode*root,int& maxi){
    if(root==NULL)return 0;
    int lh=max(0,func(root->left,maxi));
    int rh=max(0,func(root->right,maxi));

    maxi=max(maxi,root->val+lh+rh);
    return root->val+max(lh,rh);
}
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
         func(root,maxi);
         return maxi;
    }
};