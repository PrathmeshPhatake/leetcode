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
 //IF DEPTH IS ONE THEN NEW NODE CRAETE AND  ADD TO THE LEFT OF THIS NODE 
class Solution {
public:
TreeNode* add(TreeNode* root,int val,int depth,int crrDepth)
{
   if(root==NULL)
   {
    return NULL;
   }
   if(crrDepth==depth-1)
   {
     TreeNode* templeft=root->left;
     TreeNode* tempright=root->right;
     //insert new value at  given depth 
     root->left=new TreeNode(val);
     root->right=new TreeNode(val);
     //root is new node is connect to given left node and right node
     root->left->left=templeft;
     root->right->right=tempright;
      
   }
   root->left=add(root->left,val,depth,crrDepth+1);
    root->right=add(root->right,val,depth,crrDepth+1);
   return root;
}
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* Newroot=new TreeNode(val);
             Newroot->left=root;
             return Newroot;
        }
        add(root,val,depth,1);
        return root;        
    }
};