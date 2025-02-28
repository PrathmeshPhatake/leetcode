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
    vector<int> rightSideView(TreeNode* root) {
        // start moving from left to right and getting right lement at last 
        queue<TreeNode*>q;
        vector<int>ans;
        q.push(root);
        if(root==NULL) return {};
        while(!q.empty())
        {
            int rightmost=0;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode*node=q.front();
                q.pop();
                rightmost=node->val;
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(rightmost);

        }
        return ans;
    }
};