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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==NULL) return 0;
        q.push(root);
        int maxi=INT_MAX;
        int count=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*root=q.front();
                q.pop();
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            count++;
        }
        return count;
    }
};