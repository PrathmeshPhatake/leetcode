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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>in_map;
        for(int i=0;i<inorder.size();i++)
        {
            in_map[inorder[i]]=i;

        }

        TreeNode* root=build(inorder,0,inorder.size()-1,postorder,0, postorder.size()-1,in_map);
        return root;

    }
    TreeNode* build(vector<int>& inorder,int instart,int inend, vector<int>& postorder,int prestart,int preend,map<int,int>&in_map)
    {
        if(prestart>preend || instart>inend)
        {
            return nullptr;
        }
        TreeNode*root=new TreeNode(postorder[preend]);
        int root_in=in_map[postorder[preend]];
        int nums_left=root_in-instart-1;
        root->left = build(inorder,instart,instart+nums_left,postorder,prestart,prestart+nums_left,in_map);
        root->right = build(inorder,root_in+1,inend,postorder,prestart+nums_left+1,preend-1,in_map);
        return root;
        
    }
};