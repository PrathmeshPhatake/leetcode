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
int dfs(int &maxsum,TreeNode*root)
{
    if(root==NULL) return 0;
    int left=max(0,dfs(maxsum,root->left));
    int right=max(0,dfs(maxsum,root->right));
    maxsum=max(maxsum,left+right+root->val);
    return max(left,right)+root->val;
}
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        dfs(maxsum,root);
        return maxsum;
    }
};