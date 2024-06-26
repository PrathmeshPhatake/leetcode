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
 //time complexity =INORDER[O[n]]+ create[O[n]]
class Solution {
public: 
     //create  Iorder 
    void Inorder(TreeNode*root,vector<int>&inorder)
    {
        if(root==NULL)
        {
            return;
        }
        Inorder(root->left,inorder);
        inorder.push_back(root->val);
        Inorder(root->right,inorder);
        
    }
    //then we get treee based on merger sort algorithm [left,mid,right]
    TreeNode* create(vector<int>&inorder,int left,int right)
    {
        if(left>right)
        {
            return NULL;
        }
        int mid=left+(right-left)/2;
        TreeNode*root=new TreeNode(inorder[mid]);
        root->left=create(inorder,left,mid-1);
        root->right=create(inorder,mid+1,right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        Inorder(root,inorder);
        TreeNode*temp=create(inorder,0,inorder.size()-1);
        return temp;
    }
};