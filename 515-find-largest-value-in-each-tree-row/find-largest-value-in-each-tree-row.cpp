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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        int maxi=INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        if(root==NULL) return ans;
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node!=NULL)
            {
                maxi=max(maxi,node->val);
                if(node->left!=NULL)
                {
                    q.push(node->left);

                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            else
            {
                ans.push_back(maxi);
                maxi=INT_MIN;
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
        }
        return ans;

    }
};