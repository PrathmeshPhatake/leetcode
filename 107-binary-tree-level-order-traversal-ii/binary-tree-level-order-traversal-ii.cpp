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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return { };
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        vector<int>temp;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
           
            if(node!=NULL) temp.push_back(node->val);
            if(node==NULL)
            {
                if(!q.empty())
                {
                    q.push(NULL);
                }
                ans.push_back(temp);
                temp.clear();
                
            }
            else
            {
                
                if(node->left)
                {
                    q.push(node->left);

                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
        }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};