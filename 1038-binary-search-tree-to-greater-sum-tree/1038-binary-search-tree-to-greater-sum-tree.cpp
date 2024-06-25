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
//TIME COMPLEXITY :O(n);
//SPACE COMPLEXITY: BEST O(H), WORST O(N), BLANCED TREE O(LOG(N))
class Solution {
public: 
  int sum=0;
    TreeNode* traverse(TreeNode* root)
    {
         if(root)
         {
            traverse(root->right);
            sum+=root->val;;
            root->val=sum;
            traverse(root->left);
         }
         return root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        return root;
    }
};