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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode*curr=root;
        vector<int>pre;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                pre.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode*prev=curr->left;
                while(prev->right && prev->right!=curr)
                {
                   prev=prev->right;   
                }
                if(prev->right==NULL)
                    {
                        pre.push_back(curr->val);
                        prev->right=curr;
                        curr=curr->left;
                    }else
                    {
                        prev->right=NULL;
                        curr=curr->right;
                    }
            }
        }
         return pre;
    }
};